#include "encode.h"
#include "coding.h"

void Encode::encodeFile(std::string filename)
{
	input.open(filename);
	string temp = filename.substr(0,filename.size()-4) + "Encoded.enc";

	output.open(temp);

	while(input.get(toCode)){
		if(toCode ==' '){
			output.put(' ');
		}else{
			output.put(encode(toCode));
		}
	}

	input.close();
	output.close();
}


int main()
{	
	cout<<"Give filename: ";
	std::string filename;
	cin >> filename;
	Encode encoder;
	encoder.encodeFile(filename);
}
