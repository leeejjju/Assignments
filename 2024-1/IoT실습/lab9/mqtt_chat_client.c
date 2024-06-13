#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <pthread.h>
#include <mosquitto.h>
#define MQTT_HOST 	"test.mosquitto.org"
#define MQTT_PORT   1883
#define MQTT_TOPIC  "jjlee/chat"
#define BUF_SIZE 	1024
char* client_id;


void on_sub_connect(struct mosquitto *mosq, void *obj, int rc){

	printf("# connected as subscriber: %s\n", mosquitto_connack_string(rc));
	if(rc != 0) mosquitto_disconnect(mosq);

	/* Making subscriptions in the on_connect() callback means that if the
	 * connection drops and is automatically resumed by the client, then the
	 * subscriptions will be recreated when the client reconnects. */
	rc = mosquitto_subscribe(mosq, NULL, MQTT_TOPIC, 1);
	if(rc != MOSQ_ERR_SUCCESS){
		fprintf(stderr, "Error subscribing: %s\n", mosquitto_strerror(rc));
		mosquitto_disconnect(mosq);
	}

}

void on_subscribe(struct mosquitto *mosq, void *obj, int mid, int qos_count, const int *granted_qos){
	int i;
	bool have_subscription = false;

	for(i = 0; i < qos_count; i++){
	//	printf("on_subscribe: %d:granted qos = %d\n", i, granted_qos[i]);
		if(granted_qos[i] <= 2){
			have_subscription = true;
		}
	}
	if(have_subscription == false){
		fprintf(stderr, "Error: All subscriptions rejected.\n");
		mosquitto_disconnect(mosq);
	}
}



void on_pub_connect(struct mosquitto *mosq, void *obj, int rc){

	printf("# connected as publisher: %s\n", mosquitto_connack_string(rc));
	if(rc != 0) mosquitto_disconnect(mosq);

}

void on_publish(struct mosquitto *mosq, void *obj, int mid){
	//idk what to do...
}


static void on_message(struct mosquitto *mosq, void *obj, const struct mosquitto_message *msg){
    // TODO
	printf("%s\n", (char*)msg->payload);

}



void* subscribe_routine(void* arg){

	struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
	int rc;

	/* Create a new client instance.*/
	if(mosq == NULL){
		fprintf(stderr, "Error: Out of memory.\n");
		exit(1);
	}

	/* Configure callbacks. This should be done before connecting ideally. */
	mosquitto_connect_callback_set(mosq, on_sub_connect);
	mosquitto_subscribe_callback_set(mosq, on_subscribe);
	mosquitto_message_callback_set(mosq, on_message);
		
	/* connect start, for subscribe */
	rc = mosquitto_connect(mosq, MQTT_HOST, MQTT_PORT, 60);
	if(rc != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
		exit(1);
	}
	
	//subscribe routine
	rc = mosquitto_loop_forever(mosq, -1, 1);
	if(rc != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
		exit(1);
	}
	mosquitto_lib_cleanup();
	return NULL;

}


void* publish_routine(void* arg){

	struct mosquitto *mosq = mosquitto_new(NULL, true, NULL);
	char payload[BUF_SIZE];
	char buffer[BUF_SIZE];
	int rc;

	/* Create a new client instance.*/
	if(mosq == NULL){
		fprintf(stderr, "Error: Out of memory.\n");
		exit(1);
	}

	/* Configure callbacks. This should be done before connecting ideally. */
	mosquitto_connect_callback_set(mosq, on_pub_connect);
	mosquitto_publish_callback_set(mosq, on_publish);
	
	/* connect start, for publish*/
	if((rc = mosquitto_connect(mosq, MQTT_HOST, MQTT_PORT, 60)) != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
		exit(1);
	}

	/* for processing */
	rc = mosquitto_loop_start(mosq);
	if(rc != MOSQ_ERR_SUCCESS){
		mosquitto_destroy(mosq);
		fprintf(stderr, "Error: %s\n", mosquitto_strerror(rc));
		exit(1);
	}

	/* for chat */
	printf("Welcome to chat. Type \"quit\" to exit.\nHave fun :)\n\n");
	while(1){
		fgets(buffer, BUF_SIZE, stdin);
		buffer[strlen(buffer)-1] = 0;
		if(!strcmp(buffer, "quit")) break;

		sprintf(payload, "[user %s] %s", client_id, buffer);
		rc = mosquitto_publish(mosq, NULL, MQTT_TOPIC, strlen(payload), payload, 2, false);
		if(rc != MOSQ_ERR_SUCCESS) fprintf(stderr, "Error publishing: %s\n", mosquitto_strerror(rc));

	}

	mosquitto_lib_cleanup();
	return NULL;

}


int main(int argc, char *argv[]){

    if (argc != 2) {
        printf("Usage: %s <ClientID> \n", argv[0]);
        exit(1);
    }client_id = argv[1];

	mosquitto_lib_init(); //init mosquitto
	pthread_t subscribe_t, publish_t; //multy threading...

	int stat2 = pthread_create(&publish_t, NULL, publish_routine, NULL);
	int stat1 = pthread_create(&subscribe_t, NULL, subscribe_routine, NULL);
    if ((stat1 || stat2) != 0) {
        perror("Failed to create threads");
        return 1;
    }

	stat1 = pthread_join(subscribe_t, NULL);
	stat2 = pthread_join(publish_t, NULL);
    if ((stat1 || stat2) != 0) {
        perror("Failed to join threads");
        return 1;
    }


    return 0;

}



