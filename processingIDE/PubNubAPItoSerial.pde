import http.requests.*;
import processing.serial.*;

Serial myPort;  // Create object from Serial class
int val;

public void setup() {
  size(400, 400);
 String portName = Serial.list()[0];
 

  String pubkey= ""; //your pubkey from pubnub
  String subkey= ""; //your subkey from pubnub
  String channel = ""; //your channel from pubnub
  String uuid= ""; //your uuid from pubnub
  String timetoken ="0";
   GetRequest get1 = new GetRequest("https://ps.pndsn.com/subscribe/"+subkey+"/"+channel+"/0/"+timetoken+"?&uuid="+uuid);
 
 //logic deals with a single message and fetches the id to be send
 
  get1.send(); // d program will wait untill the request is completed
 
  String S1 = (String)get1.getContent();
  timetoken=S1.split(",")[1].replace("\"","").replace("]","");
  
  JSONArray resp1 = parseJSONArray(get1.getContent());
  JSONArray response1 = resp1.getJSONArray(0);
  println(response1);
  myPort = new Serial(this, portName, 9600);
  do{    
  GetRequest get = new GetRequest("https://ps.pndsn.com/subscribe/"+subkey+"/"+channel+"/0/"+timetoken+"?&uuid="+uuid); 
  get.send(); // d program will wait untill the request is completed
  
  String S = (String)get.getContent();
  timetoken=S.split(",")[2].replace("\"","").replace("]","");
  
  JSONArray resp = parseJSONArray(get.getContent());
  JSONArray response = resp.getJSONArray(0);
  JSONObject Value = response.getJSONObject(0);
  println(Value.get("id"));
  myPort.write(Value.get("id").toString());  
  
}while (true);  
 
}





    
  
