#include "HGUNet.h"



char printBinary(uint8_t data, int bit){

	uint8_t offset = 1 << bit-1;
	for(int i = 0; i < bit; i++){
		cout << ((data&offset)!=0)?1:0;
		offset >>= 1;
	}
	return ' ';
}

void printMBuffer(char* mBuffer, int mHead){
	for(int i = 0; i < mHead; i += 4) cout << printBinary((uint8_t)mBuffer[i], 8) << printBinary((uint8_t)mBuffer[i+1], 8) <<printBinary((uint8_t)mBuffer[i+2], 8) <<printBinary((uint8_t)mBuffer[i+3], 8) << endl;
}

void OutputMemoryStream::ReallocBuffer(uint32_t inNewLength)
{
	mBuffer = static_cast< char* >( std::realloc( mBuffer, inNewLength ) );
	//handle realloc failure
	//...
	mCapacity = inNewLength;
}

void OutputMemoryStream::Write(const void* outData, size_t outByteCount)
{
	//make sure we have space...
	uint32_t resultHead = mHead + static_cast<uint32_t>(outByteCount);
	if (resultHead > mCapacity)
	{
		ReallocBuffer(std::max(mCapacity * 2, resultHead));
	}
	
	//copy into buffer at head
	std::memcpy(mBuffer + mHead, outData, outByteCount);
	
	//increment head for next write
	mHead = resultHead;
}

// Lab#6
//write outBitCount bits of outData on mBuffer
void OutputMemoryStream::WriteBits(uint8_t outData, size_t outBitCount){
	// determine the position to write using mHead and mBitHeead
	char* head = mBuffer + mHead;
	uint8_t data = outData;
	if((mBitHead + outBitCount) <= 8){
		//shift data to make room for exist bits, and add them
		data << mBitHead;
		*head |= data;
		if((mBitHead + outBitCount) == 8){
			mBitHead = 0;
			mHead++;
		}else mBitHead += outBitCount;
	}else{

		//separate bits for first and second
		uint8_t restData = data;
		restData >>= (8 - mBitHead); //keep rest data
		data <<= mBitHead;
		*head |= data;
		head++; //movin to next byte
		*head |= restData;

		mBitHead = outBitCount - (8 - mBitHead);
		mHead++;

	}
		

	cout << "[writeBits] head: " << mHead << ", bitHead: " << printBinary(mBitHead, 8) << ", mBitData: " << printBinary(outData, outBitCount) << " mBuffer: " << printBinary(*head, 8) << endl;
	
}	

void InputMemoryStream::Read(void* inData,
							 uint32_t inByteCount)
{
	uint32_t resultHead = mHead + inByteCount;
	if (resultHead > mCapacity)
	{
		//handle error, no data to read!
		//...
	}
	
	std::memcpy(inData, mBuffer + mHead, inByteCount);
	
	mHead = resultHead;
}


// Lab#6
//read outBitCount bits of mBuffer and save into inData
void InputMemoryStream::ReadBits(uint8_t& inData, size_t inBitCount){

	inData = 0;
	// determine the position to read using mHead and mBitHeead
	char* head = mBuffer + mHead;
	//get datas and shift them for remove other bits
	inData = *head;
	inData >>= mBitHead;
	

	if(inBitCount <= (8 - mBitHead)){ //if all we wants are in the first byte
		//masking for remove other bits
		uint8_t mask = ((255 << inBitCount) ^ 255);
		inData &= mask;	
		if(inBitCount == (8 - mBitHead)){
			mBitHead = 0;
			mHead++;
		}else mBitHead += inBitCount;
	}else{ //if not enough at first byte...
		int restBitCount = inBitCount - (8 - mBitHead);	
		head++; //move on to the second byte
		uint8_t restData = *head; //get data and masking for remove other bits
		uint8_t mask = ((255 << restBitCount) ^ 255);
		restData &= mask;
		restData <<= (8 - mBitHead); //make rooms for rest bits
		inData |= restData;

		mBitHead = restBitCount;
		mHead++;

	}
		
	cout << "[readBits] head: " << mHead << ", bitHead: " << printBinary(mBitHead, 8) << ", mBitData: " << printBinary(inData, inBitCount) << " mBuffer: " << printBinary(*head, 8) << endl;
	
}


