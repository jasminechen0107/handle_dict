#include<stdio.h>
#include<string.h>
#include<stdlib.h>

#define MAXLINE 24 
#define MAXWORD 24

//採utf-8編碼(中文一個字3bytes，其他則1byte)

int extractWord(char line[],char word[]){
		int i, j = 0;
		char str[40];
		for(i = 0; line[i] != ' ' && line[i] != '\0'; i++){
				if(line[i] != ' '){
					str[j++] = line[i];
				}
		}
		str[j] = '\0';
		if(j > 21)
				return 1;
		else{
			strcpy(word, str);
			return 0;
		}
}

int checkWord(char word[]){
		int d;
		if(strcmp(word, " ") == 0)
				return 1;
		else{
			if(strlen(word) <= 3 && (d = word[0]) < 0)
					return 1;
			else
					return 0;
		}
}
int checkCp(int pos,int nocp[],int np){
		int i;
		for(i=0;i<np;i++)
				if(nocp[i] == pos)
						return 1;
		return 0;
}
int main(void){
		int n, len, i, j, n2,nocp[5],np;
		char line[MAXLINE], word[MAXWORD], line2[MAXLINE]; //,words[100000][MAXWORD] ;
		FILE *fin,*fin2, *fout;

		fin = fopen("dict-12-revised.txt","r");
		//fin = fopen("test.txt", "r");
		//fout =  fopen("dict_zhTW.txt", "w");
		fout = fopen("dict-1234.txt","w");
		n = 0;
		np = 0;
		while(fgets(line, MAXLINE, fin)){
				fprintf(fout,"%s",line);
				fin2 = fopen("dict-34-revised.txt","r");
				n2 = 0;
  				while(fgets(line2, MAXLINE, fin2)){
						if(strcmp(line,line2) == 0){
								np++;
								//nocp[np++] = n2;
								break;
						}
						n2++;
				}
				fclose(fin2);
		}
		fclose(fin);
		printf("np:%d\n",np);
		i=0;
		/*fin2 = fopen("dict-34-revised.txt","r");
		while(fgets(line2, MAXLINE, fin2)){
				if(checkCp(i,nocp, np) == 0)
						fprintf(fout,"%s",line2);
				i++;
		}	
		fclose(fin2);*/
				//if(extractWord(line, word) == 0)
				//	strcpy(words[n++], line);						
		printf("已完成存取\n");	
		
		
		/*
		for(i = 0; i < n; i++){
				if(checkWord(words[i]) == 0){
						for(j = i+1; j < n; j++){
							if(strcmp(words[i], words[j]) == 0){
								strcpy(words[j]," ");
								break;
							}
						}
						fprintf(fout, "%s\n", words[i]);
				}
				if(i % 10000 == 0)
						printf("已完成%d行\n",i);				
		}
		*/
		fclose(fout);
		return 0;
}
