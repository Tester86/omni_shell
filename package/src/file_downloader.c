#include <curl/curl.h>
#include <stdio.h>

int main(int argc, char* argv[]){

	CURL* curl;
	FILE* f;
	int result;

	f = fopen(argv[2], "wb");

	curl = curl_easy_init();

	curl_easy_setopt(curl, CURLOPT_URL, argv[1]);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, f);
	curl_easy_setopt(curl, CURLOPT_FAILONERROR, 1L);

	result = curl_easy_perform(curl);

	if(result == CURLE_OK){
		printf("File downloaded successfully");
	} else {
		printf("Error when downloading file\n");
		printf("Error: %s", curl_easy_strerror(result));
	}

	fclose(f);
	curl_easy_cleanup(curl);
	return 0;
}