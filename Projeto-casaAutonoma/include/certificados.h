#include <Arduino.h>

const char *AWS_BROKER = "a3lqfp1r14p6b8-ats.iot.us-east-1.amazonaws.com";
static const char AWS_ROOT_CA[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDQTCCAimgAwIBAgITBmyfz5m/jAo54vB4ikPmljZbyjANBgkqhkiG9w0BAQsF
ADA5MQswCQYDVQQGEwJVUzEPMA0GA1UEChMGQW1hem9uMRkwFwYDVQQDExBBbWF6
b24gUm9vdCBDQSAxMB4XDTE1MDUyNjAwMDAwMFoXDTM4MDExNzAwMDAwMFowOTEL
MAkGA1UEBhMCVVMxDzANBgNVBAoTBkFtYXpvbjEZMBcGA1UEAxMQQW1hem9uIFJv
b3QgQ0EgMTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBALJ4gHHKeNXj
ca9HgFB0fW7Y14h29Jlo91ghYPl0hAEvrAIthtOgQ3pOsqTQNroBvo3bSMgHFzZM
9O6II8c+6zf1tRn4SWiw3te5djgdYZ6k/oI2peVKVuRF4fn9tBb6dNqcmzU5L/qw
IFAGbHrQgLKm+a/sRxmPUDgH3KKHOVj4utWp+UhnMJbulHheb4mjUcAwhmahRWa6
VOujw5H5SNz/0egwLX0tdHA114gk957EWW67c4cX8jJGKLhD+rcdqsq08p8kDi1L
93FcXmn/6pUCyziKrlA4b9v7LWIbxcceVOF34GfID5yHI9Y/QCB/IIDEgEw+OyQm
jgSubJrIqg0CAwEAAaNCMEAwDwYDVR0TAQH/BAUwAwEB/zAOBgNVHQ8BAf8EBAMC
AYYwHQYDVR0OBBYEFIQYzIU07LwMlJQuCFmcx7IQTgoIMA0GCSqGSIb3DQEBCwUA
A4IBAQCY8jdaQZChGsV2USggNiMOruYou6r4lK5IpDB/G/wkjUu0yKGX9rbxenDI
U5PMCCjjmCXPI6T53iHTfIUJrU6adTrCC2qJeHZERxhlbI1Bjjt/msv0tadQ1wUs
N+gDS63pYaACbvXy8MWy7Vu33PqUXHeeE6V/Uq2V8viTO96LXFvKWlJbYK8U90vv
o/ufQJVtMVT8QtPHRh8jrdkPSHCa2XV4cdFyQzR1bldZwgJcJmApzyMZFo6IQ6XU
5MsI+yMRQ+hDKXJioaldXgjUkK642M4UwtBV8ob2xJNDd2ZhwLnoQdeXeGADbkpy
rqXRfboQnoZsG4q5WTP468SQvvG5
-----END CERTIFICATE-----
)EOF";
static const char AWS_CERT[] PROGMEM = R"EOF(
-----BEGIN CERTIFICATE-----
MIIDWTCCAkGgAwIBAgIUdsaj2FjVIWPu/i2NlI4GiJLR3LMwDQYJKoZIhvcNAQEL
BQAwTTFLMEkGA1UECwxCQW1hem9uIFdlYiBTZXJ2aWNlcyBPPUFtYXpvbi5jb20g
SW5jLiBMPVNlYXR0bGUgU1Q9V2FzaGluZ3RvbiBDPVVTMB4XDTI1MDYwOTE3MDEz
MVoXDTQ5MTIzMTIzNTk1OVowHjEcMBoGA1UEAwwTQVdTIElvVCBDZXJ0aWZpY2F0
ZTCCASIwDQYJKoZIhvcNAQEBBQADggEPADCCAQoCggEBAN3pRR9m8D/NH3GRM7Z3
yPkfnk7y3kduSaYIbUh2EIHLAB77frsD57aSskIS4zZWQet8mPky51EErELn+8XS
kJV2gyoVAUGxOhFSCoUK/GeAuF25yV+u620blOX6VTmZrH2C2VYXW/6KUXZFtXzw
3j2Q0FlVYlhSkVtHIHOpqkd4kPb71TVTy/ogaH2A/pj9Ljok6ZuVCQ5Kt0U98lOb
YitGbMqGafc9G1Zv7o2kCO0rJh9/68boJN/U4gtT+ygaToWiWUGb4Ata2nbzcoOP
gCkb4R4aq6jMxNymkBlA4aFeh4oeMDVWKnJqyNWa3V+NLK9PYekgic5W6tAwJshp
SjMCAwEAAaNgMF4wHwYDVR0jBBgwFoAUgrN9Mz56rUYGoseFTs2MDghcQNIwHQYD
VR0OBBYEFFfvN3UEdOEZrjWwwZSXCEqSnK++MAwGA1UdEwEB/wQCMAAwDgYDVR0P
AQH/BAQDAgeAMA0GCSqGSIb3DQEBCwUAA4IBAQCXmgBMCxV8/9qfslKCX7G94giH
by6vfGUr5CRSoFkVe4CH/QDzdeWNZK9QACosBTxCAuHy1a6gqo6JYvcToj8TbOAn
Mz2liXH3AhrcP1KJFaPiBiIK/Lo9mEaM5rZ2PTnodJrpWj+smM89S94Ga8MUpmWb
jcty7ZoK/JkrHjr7TwIwObxw4AFzXVeFTZtbNkBkcUzIArlHB0n9wHRHABZQHP32
QhijKl2P0ZUJUbzVT8206lzB91FjiGYxKTD2q2IYG0B9c1LSHWznWx2ZDDHnyxap
nyiU/eKrpYhTIKa1GVT0VrRpT6QnS/9yOjN+o5zDiU1v3CAicJw6Qc7rT4AX
-----END CERTIFICATE-----
)EOF";
static const char AWS_KEY[] PROGMEM = R"EOF(
-----BEGIN RSA PRIVATE KEY-----
MIIEogIBAAKCAQEA3elFH2bwP80fcZEztnfI+R+eTvLeR25JpghtSHYQgcsAHvt+
uwPntpKyQhLjNlZB63yY+TLnUQSsQuf7xdKQlXaDKhUBQbE6EVIKhQr8Z4C4XbnJ
X67rbRuU5fpVOZmsfYLZVhdb/opRdkW1fPDePZDQWVViWFKRW0cgc6mqR3iQ9vvV
NVPL+iBofYD+mP0uOiTpm5UJDkq3RT3yU5tiK0ZsyoZp9z0bVm/ujaQI7SsmH3/r
xugk39TiC1P7KBpOhaJZQZvgC1radvNyg4+AKRvhHhqrqMzE3KaQGUDhoV6Hih4w
NVYqcmrI1ZrdX40sr09h6SCJzlbq0DAmyGlKMwIDAQABAoIBAEaVBJxZVH8mkiLA
KW+XKAA9E1BPJW4Y4SoDMidDDjsKQ26XVZbMRi4m+LXVZhmJVAw/pDRXAYYec2AQ
g19Hex9fA5cl+TFY2nxZ2Oi6NtAA/CMrjaZ2b4FTrYd8mRDqFRgSv2gHpAYRHpn8
0B3+SuHQJsTTSKWJFZyvwd2oEHYMhnxzn7PbeaH+cS37V5vUG6PZKLRt2RwCL/Mq
koJFHInOOvrAfwI5RldUJt6Fm4I1agnF/MLP45CWgum4PGAGQZHqPMVzlM6IzAvo
M5eryH+Bc+wOiifB0Xs0uQK2hJDCPh06yr1ewa84BQQhAmIALSuPEbuc9ZEqT/6x
nJo2kdECgYEA9EbG1GTw0JYVC1VnjB+ZhqZ27ULOVSMqrPdtbHRWNocfjaDFtu8M
yKICI6FWkxfMAkziBuorpK/9uPpdt36EmAAAt8HACzqH3BRzx/lHj6ixAvhN+Pb/
p/EHVwjIJbal2ebu/2I0GI40ceUglJLu+pxB6LP6HS7humKR8EtB+vsCgYEA6I+1
uEBQisE+smULUQ4d/YVNCCEiytY4Ey3KjuzevGmAAsEGmBpZXBFg7pEfJdYlc9T5
dJpcdS1Ysg8xEK4obaGloEZwrONsNLINgcr/d2sihtW7uRCWVhOR6FKpDo2buI/U
l9+nWzKhgHXDrq7wnLPPQPOiU4sVud28ulEMyCkCgYAuxS5klD8XcOTumpeM2LAI
e+7hVp0y59zP6T/mOBAZuJ1t/I5ejD6iW4KVV9q/pxrEhfvw3v0kNx4ZQLaY33x7
reR1Sn9+puJEXRYd/7iX5PCfZPNo68HfYeLJ40CPF/2BTxoLg739xZx9AiXOzKM9
EJX9/BezZrqJeT4ACCjF6QKBgE5fj/gGBJ6ePUjVcJjiTw0PDUS+FgGRa9hayDae
cPnB/BfxgQ1lY9P5L1d2pK6Vmo2Mqny3QI1kuM1Y/UoHxywbG7wFwRcilWa00oR5
KtrNyhbylI7rnh5n/fXzVXHIG0B5iEWeY8ICMBcgmM+XuRK2LhRPhtbsumem6GFJ
yyrxAoGAf7QMOeBecEkt+SKtXyZmdFKXpPwDqnMA1wmrXouZSt1COE29a9QHD0T6
KBo9efj89A15X1HUHLNVJGkLKUOt6M3mQAuApnpZTYnqtsW5ngCjo/emlxxN3x6v
U9CG9Ov3sAfF1UseoQYKiEZ/oZ4ZVHEgdzkB6j0wnGGUMvW2OUQ=
-----END RSA PRIVATE KEY-----
)EOF";
