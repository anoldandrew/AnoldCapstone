#ifndef emails_H
#define emails_H
#include "wifi_code.h"
#include "ESP32_MailClient.h"

// To send Emails using Gmail on port 465 (SSL), you need to create an app password: https://support.google.com/accounts/answer/185833
#define emailSenderAccount    "espcapstone@gmail.com"  
#define emailSenderPassword   "ilkygvpyisbbmbxk"
#define emailRecipient        "anoldnsubuga4@gmail.com"
#define smtpServer            "smtp.gmail.com"
#define smtpServerPort        465
#define emailSubject         "Airquality Update from ESP"

SMTPData smtpData;
void sendCallback(SendStatus info);

void email(){
  if(WiFi.status()== WL_CONNECTED){

  // Set the SMTP Server Email host, port, account and password
  smtpData.setLogin(smtpServer, smtpServerPort, emailSenderAccount, emailSenderPassword);
  // Set the sender name and Email
  smtpData.setSender("ESP32", emailSenderAccount);
  // Set Email priority or importance High, Normal, Low or 1 to 5 (1 is highest)
  smtpData.setPriority("High"); 
    // Set the subject
  smtpData.setSubject(emailSubject);
      // Set the message with HTML format
  smtpData.setMessage("<div style=\"color:#2f4468;\"><h1>Air quality control requires manual intervation</h1><p>- Sent from ESP32 board</p></div>", true);
    // Add recipients, you can add more than one recipient
  smtpData.addRecipient(emailRecipient);
  smtpData.setSendCallback(sendCallback);
    if (!MailClient.sendMail(smtpData))
    Serial.println("Error sending Email, " + MailClient.smtpErrorReason());

  //Clear all data from Email object to free memory
  smtpData.empty();
  }
  
}

// Callback function to get the Email sending status
void sendCallback(SendStatus msg) {
  // Print the current status
  Serial.println(msg.info());

  // Do something when complete
  if (msg.success()) {
    Serial.println("----------------");
  }
}



#endif 
