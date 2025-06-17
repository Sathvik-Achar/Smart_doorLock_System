#define bt_1 A5
#define bt_2 A2
#define bt_3 A1
#define bt_4 A0
#define log_out 13
#define bt_lock 11
#define bt_unlock 12
#define c_motor 5
#define ac_motor 7

boolean lock_status= 0;
String psw="123";
String e_psw;


    
void setup()
{
  pinMode(bt_1, INPUT_PULLUP);
  pinMode(bt_2, INPUT_PULLUP);
  pinMode(bt_3, INPUT_PULLUP);
  pinMode(bt_4, INPUT_PULLUP);
  pinMode(log_out, INPUT_PULLUP);
  pinMode(bt_lock, INPUT_PULLUP);
  pinMode(bt_unlock, INPUT_PULLUP);
  pinMode(c_motor, OUTPUT);
  pinMode(ac_motor, OUTPUT);
  Serial.begin(9600);
  Serial.println("start");
  }



void loop()
{
  if(digitalRead(bt_1)==0){
    if(e_psw.length()<3){
      e_psw=e_psw+"1";
      delay(500);
      Serial.println(e_psw);
      }
  }
   else if(digitalRead(bt_2)==0){
       if(e_psw.length()<3){
      e_psw=e_psw+"2";
      delay(500);
       Serial.println(e_psw);
      }
     }
  else if(digitalRead(bt_3)==0){
       if(e_psw.length()<3){
      e_psw=e_psw+"3";
      delay(500);
       Serial.println(e_psw);
      }
     }
   else if(digitalRead(bt_4)==0){
       if(e_psw.length()<3){
      e_psw=e_psw+"4";
      delay(500);
       Serial.println(e_psw);
      }
   
     }
  //Serial.println(e_psw);
  
       if(digitalRead(log_out)==0){
      e_psw="";
      delay(500);
     Serial.println("successfully logout!");
      }
   
  
	if(digitalRead(bt_lock)==0){
     	if(psw==e_psw){
   			if(lock_status==0){
     			lock();
             // Serial.println("successfully locked!");
              delay(1000);
      			}
     	
          else{
      		Serial.println("already locked!");
            delay(1000);}
  		}
      else{
       Serial.println("Invalid password!");
        delay(1000);}
   		}
    else if(digitalRead(bt_unlock)==0){
      	if(psw==e_psw){
             if(lock_status==1){
     			 unlock();
               delay(1000);
        		}
          else{
          		Serial.println("already unlocked!");
          			delay(1000);
          }

  				}
          else{
           Serial.println("Invalid password!");
            delay(1000);}
    }

}

void lock()
{
    digitalWrite(c_motor, 1);
    digitalWrite(ac_motor, 0);
    delay(1000);
    digitalWrite(c_motor, 0);
    digitalWrite(ac_motor, 0);
    Serial.println("successfully locked");
    lock_status= 1;
}
void unlock(){
    digitalWrite(c_motor, 0);
    digitalWrite(ac_motor, 1);
    delay(1000);
    digitalWrite(c_motor, 0);
    digitalWrite(ac_motor, 0);
    Serial.println("successfully unlocked");
    lock_status= 0;
  }