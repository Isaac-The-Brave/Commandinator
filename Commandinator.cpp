#include <stdio.h>
#include <curl/curl.h>
#include <iostream>
#include <string>
#include <sstream>
#include <json/json.h>
#include <json/value.h>


using std::cout;
using std::endl;
std::string urlencode(const std::string &c);


//Curl SaveFunction https://stackoverflow.com/questions/2329571/c-libcurl-get-output-into-a-string

size_t CurlWrite_CallbackFunc_StdString(void *contents, size_t size, size_t nmemb, std::string *s)
{
    size_t newLength = size*nmemb;
    try
    {
        s->append((char*)contents, newLength);
    }
    catch(std::bad_alloc &e)
    {
        //handle memory problem
        return 0;
    }
    return newLength;
}


int main(void)
{


  std::string firstname;
  std::cout << "Please input the command you'd like to know:\n";
  std::cout << "\n";
  std::getline(std::cin,firstname);

	//Create Prompt Including user's input for GPT-J
  std::string prompt = std::string("http://api.vicgalle.net:5000/generate?context=Q%3A%20Show%20the%20contents%20of%20root%20directory%0AA%3A%20ls%20%2Froot%0AQ%3A%20What%20is%20in%20the%20text%20file%20called%20lemon.txt%3F%0AA%3A%20cat%20lemon.txt%0AQ%3A%20Show%20the%20contents%20of%20the%20var%20www%20html%20directory%0AA%3A%20ls%20%2Fvar%2Fwww%2Fhtml%0AQ%3A%20Scan%20https%3A%2F%2Fwww.alphacopy.net%20with%20ffuf%20and%20run%20a%20mysql%20scan%20on%20every%20output%0AA%3A%20ffuf%20-o%20%2Ftmp%2Foutput.txt%20-u%20%27https%3A%2F%2Fwww.alphacopy.net%27%20-c%20%27sh%20-c%20%27mysql%20-u%20root%20-p%27%20%3E%20%2Ftmp%2Foutput.txt%0AQ%3A%20Install%20python3%0AA%3A%20apt-get%20install%20python3%0AQ%3A%20start%20a%20python%20http%20server%20%0AA%3A%20python3%20-m%20http.server%0AQ%3A") + urlencode(firstname) + "%0AA:&token_max_length=128&temperature=1&top_p=0.9&stop_sequence=%0A";

	//Begin the POST request to VicGalle.net GPT-J
  CURL *curl;
  CURLcode res;

  curl_global_init(CURL_GLOBAL_ALL);

  curl = curl_easy_init();
  std::string result;
  if(curl) {
    curl_easy_setopt(curl, CURLOPT_URL, prompt.c_str());
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, "context=out&token_max_length=128");
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, CurlWrite_CallbackFunc_StdString);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &result);
    res = curl_easy_perform(curl);

    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    curl_easy_cleanup(curl);
  }
  curl_global_cleanup();
  //Save result as Json Object

  Json::Value root;
  Json::Reader reader;
  bool parsingSuccessful = reader.parse(result, root);
  if (parsingSuccessful) {
    // Iterate through the json object
    for (Json::Value::iterator it = root.begin(); it != root.end(); ++it) {
    }
  }
  else {
    std::cout << "Failed to parse JSON" << std::endl;
  }

  //Print the result
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";
  std::cout << "\n";

  std::cout << "You requested: ";
  std::cout << firstname << std::endl;
  std::cout << "\n";

  std::cout << "This is what GPT-J Thinks that would look like:" << std::endl;
  std::cout << root["text"] << std::endl;
}




std::string urlencode(const std::string &s)
{
    static const char lookup[]= "0123456789abcdef";
    std::stringstream e;
    for(int i=0, ix=s.length(); i<ix; i++)
    {
        const char& c = s[i];
        if ( (48 <= c && c <= 57) ||//0-9
             (65 <= c && c <= 90) ||//abc...xyz
             (97 <= c && c <= 122) || //ABC...XYZ
             (c=='-' || c=='_' || c=='.' || c=='~')
        )
        {
            e << c;
        }
        else
        {
            e << '%';
            e << lookup[ (c&0xF0)>>4 ];
            e << lookup[ (c&0x0F) ];
        }
    }
    return e.str();
}
