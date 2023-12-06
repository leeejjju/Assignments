from flask import Flask, render_template 
from flask_mqtt import Mqtt
import json

app = Flask(__name__) 

#Set MQTT Broker Information
app.config['MQTT_BROKER_URL'] = 'sweetdream.iptime.org'
app.config['MQTT_BROKER_PORT'] = 1883
app.config['MQTT_USERNAME'] = 'iot'
app.config['MQTT_PASSWORD'] = 'csee1414'

mqtt = Mqtt(app)

#Set MQTT Topic
ys_pub_topic = 'iot/21900549'
ys_sub_topic_dht = 'iot/21900549/dht22'
ys_sub_topic_cds = 'iot/21900549/cds'
jj_pub_topic = 'iot/22100579'
jj_sub_topic_dht = 'iot/22100579/dht22'
jj_sub_topic_cds = 'iot/22100579/cds'

#Buffers for mqtt message
ys_mqtt_temperature=''
ys_mqtt_humidity=''
ys_mqtt_light=''
ys_buf_temperature=''
ys_buf_humidity=''
ys_buf_light=''
jj_mqtt_temperature=''
jj_mqtt_humidity=''
jj_mqtt_light=''
jj_buf_temperature=''
jj_buf_humidity=''
jj_buf_light=''

#Main page
@app.route('/iot/21900549/') 
def home():
  global ys_mqtt_temperature
  global ys_mqtt_humidity
  global ys_mqtt_light
  global jj_mqtt_temperature
  global jj_mqtt_humidity
  global jj_mqtt_light
  ys_mqtt_temperature = ys_buf_temperature
  ys_mqtt_humidity = ys_buf_humidity
  ys_mqtt_light = ys_buf_light
  jj_mqtt_temperature = jj_buf_temperature
  jj_mqtt_humidity = jj_buf_humidity
  jj_mqtt_light = jj_buf_light
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/dht22') 
def dht22():
  global ys_mqtt_temperature
  global ys_mqtt_humidity
  ys_mqtt_temperature = ys_buf_temperature
  ys_mqtt_humidity = ys_buf_humidity
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/cds') 
def cds():
  global ys_mqtt_light
  ys_mqtt_light = ys_buf_light
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/led') 
def led():
  mqtt.publish(ys_pub_topic,'led') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/ledon') 
def ledon():
  mqtt.publish(ys_pub_topic,'ledon') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/ledoff') 
def ledoff():
  mqtt.publish(ys_pub_topic,'ledoff') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/usbled') 
def usbled():
  mqtt.publish(ys_pub_topic,'usbled') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/usbledon') 
def usbledon():
  mqtt.publish(ys_pub_topic,'usbledon') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/21900549/usbledoff') 
def usbledoff():
  mqtt.publish(ys_pub_topic,'usbledoff') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)


@app.route('/iot/22100579/') 
def home2():
  global ys_mqtt_temperature
  global ys_mqtt_humidity
  global ys_mqtt_light
  global jj_mqtt_temperature
  global jj_mqtt_humidity
  global jj_mqtt_light
  ys_mqtt_temperature = ys_buf_temperature
  ys_mqtt_humidity = ys_buf_humidity
  ys_mqtt_light = ys_buf_light
  jj_mqtt_temperature = jj_buf_temperature
  jj_mqtt_humidity = jj_buf_humidity
  jj_mqtt_light = jj_buf_light
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)


@app.route('/iot/22100579/dht22') 
def dht22_22100579():
  global jj_mqtt_humidity
  global jj_mqtt_temperature
  jj_mqtt_temperature = jj_buf_temperature
  jj_mqtt_humidity = jj_buf_humidity
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/cds') 
def cds_22100579():
  global jj_mqtt_light
  jj_mqtt_light = jj_buf_light
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/led') 
def led_22100579():
  mqtt.publish(jj_pub_topic,'led') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/ledon') 
def ledon_22100579():
  mqtt.publish(jj_pub_topic,'ledon') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/ledoff') 
def ledoff_22100579():
  mqtt.publish(jj_pub_topic,'ledoff') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/usbled') 
def usbled_22100579():
  mqtt.publish(jj_pub_topic,'usbled') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/usbledon') 
def usbledon_22100579():
  mqtt.publish(jj_pub_topic,'usbledon') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)

@app.route('/iot/22100579/usbledoff') 
def usbledoff_22100579():
  mqtt.publish(jj_pub_topic,'usbledoff') 
  return render_template('index.html',ys_t = ys_mqtt_temperature, ys_h = ys_mqtt_humidity, ys_l = ys_mqtt_light, jj_t = jj_mqtt_temperature, jj_h = jj_mqtt_humidity, jj_l = jj_mqtt_light)


# When mqtt is connected, subscribe to following topics
@mqtt.on_connect()
def handle_connect(client, userdata, flags, rc):
  mqtt.subscribe(ys_sub_topic_dht)
  mqtt.subscribe(ys_sub_topic_cds)
  mqtt.subscribe(jj_sub_topic_dht)
  mqtt.subscribe(jj_sub_topic_cds)

# When mqtt receives message from subscribed topic
@mqtt.on_message()
def handle_mqtt_message(client, userdata, message):
  global ys_buf_temperature
  global ys_buf_humidity
  global ys_buf_light
  global jj_buf_temperature
  global jj_buf_humidity
  global jj_buf_light
  topic = message.topic
  payload = message.payload.decode()
  if topic == 'iot/21900549/cds':
    data = json.loads(payload)
    ys_buf_light = data["Light"]
    print("On message received for Yunseo\n  Light="+ str(ys_buf_light))
  elif topic == 'iot/22100579/cds':
    data = json.loads(payload)
    jj_buf_light = data["Light"]
    print("On message received for Jinju\n  Light"+ str(jj_buf_light))
  elif topic == 'iot/22100579/dht22':
    data = json.loads(payload)
    jj_buf_temperature = data["Temp"]
    jj_buf_humidity = data["Humi"]
    print("On message received for Jinju\n  Temp = "+ str(jj_buf_temperature), "Humi = "+str(jj_buf_humidity))
  elif topic == 'iot/21900549/dht22':
    data = json.loads(payload)
    ys_buf_temperature = data["Temp"]
    ys_buf_humidity = data["Humi"]
    print("On message received for Yunseo\n  Temp = "+ str(ys_buf_temperature), "Humi = ", str(ys_buf_humidity))

if __name__ == '__main__': 
  app.run(host='0.0.0.0', debug=False)