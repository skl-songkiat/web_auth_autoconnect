#include <ESP8266WiFi.h>
#include <ESP8266WebServer.h>
#include <ESP8266WebServerSecure.h>
#include <WiFiManager.h>
#include <DNSServer.h>
#include <FS.h>

DNSServer dnsServer;
BearSSL::ESP8266WebServerSecure server(443);

#define DNS_PORT    53
#define AP_IP       192,168,4,1
#define DBG_OUTPUT_PORT Serial

static const char  serverCert[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIECzCCAvOgAwIBAgIUKrysO/997zVoAado9aVk0UoDtugwDQYJKoZIhvcNAQEL
BQAwgZQxCzAJBgNVBAYTAlRIMRAwDgYDVQQIDAdiYW5na29rMRMwEQYDVQQHDApu
b250aGFidXJpMSIwIAYDVQQKDBlza2xzb25na2lhdCBkZXZlbG9wbXBtZW50MR0w
GwYDVQQLDBRkZXZlbG9wbWVudCBkZXZpc2lvbjEbMBkGA1UEAwwSZXNwc2tsc29u
Z2tpYXQuY29tMB4XDTE5MDcwNzA1MjI1NVoXDTIwMDcwNjA1MjI1NVowgZQxCzAJ
BgNVBAYTAlRIMRAwDgYDVQQIDAdiYW5na29rMRMwEQYDVQQHDApub250aGFidXJp
MSIwIAYDVQQKDBlza2xzb25na2lhdCBkZXZlbG9wbXBtZW50MR0wGwYDVQQLDBRk
ZXZlbG9wbWVudCBkZXZpc2lvbjEbMBkGA1UEAwwSZXNwc2tsc29uZ2tpYXQuY29t
MIIBIjANBgkqhkiG9w0BAQEFAAOCAQ8AMIIBCgKCAQEAsmqGQy9K2Ulbtt9XKbXJ
bR95/1PumSgGE971BXXfZ+E+VOMx7EfJFmYqH714MsWqm2bsj75qBdabvxDd1IGy
Vk1BOpB7BDxCDxvMKZyzsm2XKmcmXGs7dG5VhB3ipDFk1mZ0woMicURIoqPC3ivB
5UGgicsNDfR8j/ejdtv7jZychZ7U2HwdTlIaLOTnn93TtmpsjREZ46kUb7cftZvp
2mU2C2yYFsorjNGLDeBxwNG5D869yMr/hru/gCIYIarL7wJMkOBTighDSW6iGLCw
h/YDGwZ33vPatlI1egsrfrSQjJtmUIVwpznwZDqSlmKxJP3ZHECcEfO83sxtmonN
hQIDAQABo1MwUTAdBgNVHQ4EFgQUOJd+1JUa9466L1DakqhDDcVGxkowHwYDVR0j
BBgwFoAUOJd+1JUa9466L1DakqhDDcVGxkowDwYDVR0TAQH/BAUwAwEB/zANBgkq
hkiG9w0BAQsFAAOCAQEAGXqI8uL2ngbFEHJV9czWgUHlxevf5jLRqRpr/EWW6SOg
UKTiugmDR8CKU9inawPU55+vNXH2bg4fQPmLZ77CFnYLpKp/SCiACuSzu0yqrJLG
XPpqJOzkrQEcJw77IGI9JT+qW+wcKl23EDuwJS8kJL6ZdwiUNZT936hPqMt5kMes
1o85Gh/H5amZs6d0ZQmGK3FEqRX/7ao6o3CHjQUXUFGIgVHmBIO8SMTBa4js+PnC
4phQzuNuoawhURTYecdwoSzxIVHafG1/la4uMXofg6tk6yy2EbXhJK5KRihRlqxK
/z5hC8IZZTnNyhzyLMWH8SGvwlT+OH5Xz0L037FvoQ==
-----END CERTIFICATE-----
)EOF";

static const char  serverKey[] PROGMEM = R"EOF(
-----BEGIN PRIVATE KEY-----
MIIEvAIBADANBgkqhkiG9w0BAQEFAASCBKYwggSiAgEAAoIBAQCyaoZDL0rZSVu2
31cptcltH3n/U+6ZKAYT3vUFdd9n4T5U4zHsR8kWZiofvXgyxaqbZuyPvmoF1pu/
EN3UgbJWTUE6kHsEPEIPG8wpnLOybZcqZyZcazt0blWEHeKkMWTWZnTCgyJxREii
o8LeK8HlQaCJyw0N9HyP96N22/uNnJyFntTYfB1OUhos5Oef3dO2amyNERnjqRRv
tx+1m+naZTYLbJgWyiuM0YsN4HHA0bkPzr3Iyv+Gu7+AIhghqsvvAkyQ4FOKCENJ
bqIYsLCH9gMbBnfe89q2UjV6Cyt+tJCMm2ZQhXCnOfBkOpKWYrEk/dkcQJwR87ze
zG2aic2FAgMBAAECggEARgs+FKg/aVi8cenyrURaBMZDvfK0jFpDMI/qf69L+ttZ
/jeHxOxVzL5lMTrQMpaZqRLaMoCd3Rbo5DT58dDNM8Z2okhQk1QY1xehqoCDp7wQ
iawfSk8q80XRuuGEtdNSdD2a/zY+UlttbLR/73scTyXZod8ei+j88gRVn3czpd86
0iiwyFNU+83WBGyWJMXzrtCds6qCehhT9ZAlqtxUNL0j2CyaeFyvhJKGuyN5AFQl
vOadrZoaSrIfEJtNUwkY+/IIR47IFJj2vzhyhUjFqaqsN17AYNQ5fP9f/b1GnUGX
S9Bn4Sdw9tNwBXhqQn5sbEfQ7N47d+F2vnYcZyxa4QKBgQDn4tsb9WFx8VqaLWWS
nDTGg/ghSVpUHXbssAWOm19zqQuUeVV55GS4EjKtF9BlmoYWLMzCMKc5+qhkjy8+
Gs5QZhDL/jR7N5/5lzmsU6Kk6WjxzLV91608pQJieYc6BZG20ZX+4bSLslwYcT+r
8LkA7dJIxt74f/WQQ4oyW/1XiQKBgQDE+DgETAY6sxMfYd2cgB9Kik+LP8++yxfb
dE/57JigaMwZNvHy5Tk+u3GITmApkDhfaAOUNosxDCf0LoZRuvCKkZl+VA5h0LXi
J/EQk8zVoxCgNyIqQnOeFdch7FWc+UIqzEl+dhOB7EGF1XbmGc0AUJmB+qCMb4wQ
IXbCEnQLHQKBgHbEs9MjIHD63JwBSngIN+PBrjJmXrScjs/17DK5k+8qkzrN1qDj
AU9iSsBrZRrVRX5QHeQMhWpl3x/6Uokts6RsUogZQIon2HE/KpQAFlr/DfhjEEZP
VHSuU4Val495UMPhn0D4G8A9b3w5bRJE7ozyQnVyHrwK1hy46yyV/zF5AoGAO7jD
S1I9xUiMsMQ8rHoQgspjCeakN8ZeinS+1xmMwX5k+/Qz8iDcdY/iAaE5+QA4h30D
MMpE8+8qohgFM/zJeEpjTvFvlurwaw0PQ6Z8wf36SYnN+yBA7BrVKvz8jGbrUAy2
7/gfPBKFX2306hnClajakpWKXmpn/nAXEQsFUmUCgYAJ4WouklmdusQRan0ritfu
MyVCP3b95xhhhv+UBMag97xhLzEbJwMacZTimm7fJEXJKAqPzujpxS/YM4eNLoSe
AhDeMuOderwiGuUEHM1WtgIczxsK2E9w1RNWEA8On5auyoq3egVlo33ozHdX5id1
g3sbSn19g7J/BSJhuKrM5w==
-----END PRIVATE KEY-----
)EOF";

void setup() {
   Serial.begin(115200);

   WiFiManager wifiManager;
   IPAddress ip(AP_IP);
  
   wifiManager.autoConnect("AutoConnectAP");
   Serial.println("Connected.");
   WiFi.softAP("nodemcu_sklsongkiat");
   dnsServer.setErrorReplyCode(DNSReplyCode::NoError);
   dnsServer.start(DNS_PORT, "*", ip); 
    
   // Makes SSL
   server.setRSACert(new X509List(serverCert), new PrivateKey(serverKey));

   // Makes index page and images available
   server.on("/",HTTP_GET,handleRoot);

   // Start Web Server
   server.begin();
   Serial.println ( "HTTP server started" );
}

void loop() {
  server.handleClient();
  dnsServer.processNextRequest();
}

void handleRoot(){
   SPIFFS.begin();
   File f = SPIFFS.open("/index.html","r");
   server.streamFile(f, "text/html");
   f.close();
}
