/*P0.c*/
/*Henrique*/
/*11811ETE016*/
int main(int argc, char const *argv[])
{
	int i=0;
	if (argc>1)
	{
	if(argc>2){
		for ( i = 0; i < argv[2][0]-'0'; ++i){
			printf("Valeu,%s\n",argv[1]);
		}
	}
	else {
		printf("Saudacoes, %s\n",argv[1] );
	}
		
	}else
	printf("ola\n");
	return 0;
}