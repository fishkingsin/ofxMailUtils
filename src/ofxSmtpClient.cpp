/*
ofxMailUtils
author: arturo
*/

#include "ofxMailUtils.h"

// ----------------------------------------------------------------------
ofxSmtpClientUtils::ofxSmtpClientUtils(string host , int port){
	connected = false;
	try{
		session=new Poco::Net::SMTPClientSession(host,port);
		session->login();
		connected = true;
	}catch(Poco::Exception e){
		ofLog(OF_LOG_ERROR,"cannot connect to the server");
	}

}
ofxSmtpClientUtils::ofxSmtpClientUtils(string host , int port , string username,string password){
	connected = false;
	try{
		session=new Poco::Net::SMTPClientSession(host,port);
		session->login(Poco::Net::SMTPClientSession::LoginMethod::AUTH_LOGIN,username,password);
		connected = true;
	}catch(Poco::Exception e){
		ofLog(OF_LOG_ERROR,"cannot connect to the server");
	}
	
}
// ----------------------------------------------------------------------
ofxSmtpClientUtils::~ofxSmtpClientUtils(){

	if(session)session->~SMTPClientSession();
}
//-------------------------------
// non blocking functions
//void ofxSmtpClientUtils::addMessage(ofxMailMessage message){
//	messages.push(message);
//	if(!isThreadRunning())
//		start();
//}

//-------------------------------
// blocking functions
void ofxSmtpClientUtils::sendMessage(ofxMailMessage & message){
	if(connected)
		session->sendMessage(message.getPocoMessage());
	else
		ofLog(OF_LOG_ERROR,"cannot send, not connected to the smtp server");
}


// ----------------------------------------------------------------------
/*void ofxSmtpClientUtils::start() {
	if (isThreadRunning() == false){
		printf("thread started\n");
		startThread(true,true);
	}

}
// ----------------------------------------------------------------------
void ofxSmtpClientUtils::stop() {
	while( isThreadRunning() != 0 ){
		printf("thread trying to stop\n");
		if( lock() ){
	stopThread();
	unlock();
		}
	}
}
// ----------------------------------------------------------------------
void ofxSmtpClientUtils::threadedFunction(){

	// loop through this process whilst thread running
	//while( isThreadRunning() == true ){
	//	if(messages.size()){
	//		sendMessage(messages.front());
	//		messages.pop();
	//	}else{
	//		stop();
	//	}

	//}
	while( isThreadRunning() != 0 ){
		if( lock() ){
			if(messages.size()){
				sendMessage(messages.front());
				messages.pop();
			}else{
				stop();
			}
			unlock();
			ofSleepMillis(5);
		}
	}

}*/