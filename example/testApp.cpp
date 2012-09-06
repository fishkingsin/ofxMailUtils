#include "testApp.h"


//--------------------------------------------------------------
void testApp::setup(){
	//ofAddListener(pop3.newMessageEvent,this,&testApp::newMessage);

	ofxMailAccount account;
	account.accountId=0;
	account.accountName="account name"; // this is just to show the name of the account where the message arrive
	account.user="user name";		// login to your mail account
	account.password="password";			// password of your mail account
	account.host="host";		// pop3 server
	account.port=1199; // by default
	 
	pop3.addAccount(account);	
	pop3.setCheckInterval(20);
	pop3.start();
	 
}

//--------------------------------------------------------------
void testApp::update(){
	sprintf(message,"fps: %i",(int)ofGetFrameRate());
}

//--------------------------------------------------------------
void testApp::draw(){
	ofDrawBitmapString(message,20,20);

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){
	if(key!=27)
	{
	ofxMailMessage message;
	message.recipients.push_back("recipients");
	message.sender="sender";
	message.subject="subject of the message";
	message.content = "Hello World";
	message.attachmentPaths.push_back( "image1.png");
	message.date=Poco::Timestamp();
	ofxSmtpClientUtils smtp ("127.0.0.1",1199,"account","password");
//	smtp.addMessage(message);
	smtp.sendMessage(message);
	cout << "testApp::keyPressed: new message sent\n";
	
	}
}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){
}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){
}

//--------------------------------------------------------------
void testApp::mouseReleased(){
}



void testApp::newMessage(ofxMailMessage & message){
	cout << "\n----------------------\n";
	cout << "testApp::newMessage: \n";
	cout << "from: "<< message.sender << "\n";
	cout << "subject: "<<message.subject + "\n\n";
	cout << message.content + "\n----------------------\n\n";
}
