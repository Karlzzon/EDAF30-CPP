#include "decode.h"
#include "coding.h"

void Decode::decodeFile(std::string filename)
{
	input.open(filename);
	string temp = filename.substr(0, filename.size()-4) + "Decoded.dec";
	
	output.open(temp);

	while(input.get(toDeCode)){
		if(toDeCode==' '){
			output.put(' ');
		}else{
			output.put(decode(toDeCode));
		}
	}
	input.close();
	output.close();
}

int main(){
	cout<<"Give filename of encoded file: ";
	std::string filename;
	cin>>filename;
	Decode decoder;
	decoder.decodeFile(filename);
}
