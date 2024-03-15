#include <stdio.h>

int main() {
	char answer;
	
	do{
		char binary[32];
		char ip_maskBR[32];
		char ip_maskNW[32];
		int array_ip[4];
		int ip_broadcast[4];
		int ip_network[4];
		int ip[] = {128, 64, 32, 16, 8, 4, 2, 1};
	
		int prefix;
		int i, j, k = 0;
		
		printf("Enter the IP address [max 255]: ");
		scanf("%d.%d.%d.%d", &array_ip[0], &array_ip[1], &array_ip[2], &array_ip[3]);
		
		for(j = 0; j < 4; j++){
			for(i = 0; i < 8; i++){
				if(array_ip[j] >= ip[i]){
					binary[k] = '1';
					array_ip[j] -= ip[i];			
				}else{
					binary[k] = '0';		
				}
				k++;
			}
		}
			
		printf("\nEnter the prefix: ");
		scanf("%d", &prefix);
	
		for(k = 0; k < 32; k++){
			if((k+1) > prefix){
				ip_maskBR[k] = '1';
			}else{
				ip_maskBR[k] = binary[k];
			}
		}
			
		for(k = 0; k < 32; k++){
			if((k+1) > prefix){
				ip_maskNW[k] = '0';
			}else{
				ip_maskNW[k] = binary[k];
			}
		}
		
		k = 0;
		ip_broadcast[0] = 0;
		ip_broadcast[1] = 0;
		ip_broadcast[2] = 0;
		ip_broadcast[3] = 0;
		for(j = 0; j < 4; j++){
			for(i = 0; i < 8; i++){
				if(ip_maskBR[k] == '1'){
					ip_broadcast[j] += ip[i];
				}else{
					ip_broadcast[j] += 0;
				}
				k++;
			}
		}
		
		k = 0;
		ip_network[0] = 0;
		ip_network[1] = 0;
		ip_network[2] = 0;
		ip_network[3] = 0;
	
		for(j = 0; j < 4; j++){
			for(i = 0; i < 8; i++){
				if(ip_maskNW[k] == '1'){
					ip_network[j] += ip[i];
				}else{
					ip_network[j] += 0;
				}
				k++;
			}
		}
		
		printf("\nNetwork> %d.%d.%d.%d", ip_network[0], ip_network[1], ip_network[2], ip_network[3]);
		printf("\nBroadcast> %d.%d.%d.%d", ip_broadcast[0], ip_broadcast[1], ip_broadcast[2], ip_broadcast[3]);
		
		printf("\nDo you want to continue [Y,y|N,n]?: ");
		scanf(" %c", &answer);
		
		while(answer != 'y' && answer != 'Y' && answer != 'n' && answer != 'N'){
			printf("\nWrong answer [Y,y|N,n]?: ");
			scanf(" %c", &answer);
		}
		
	}while(answer == 'y' || answer == 'Y');

	return 0;
}