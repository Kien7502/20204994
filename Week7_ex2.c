int main(void)
{
	FILE *fp, fpout;
	phoneaddress phonearr[MAX_ELEMENT];
	int i,n, irc; // return code
	char name[20];
	int reval = SUCCESS
	printf("How many contacts do you want to enter 
	(<100)?"); scanf("%d", &n);
	if ((fp = fopen("phonebook.dat","rb")) == NULL){
		printf("Can not open %s.\n", "phonebook.dat");
		reval = FAIL;
} 
	irc = fread(phonearr, sizeof(phoneaddress), n, fp);
	printf(" fread return code = %d\n", irc); fclose(fp);
	if (irc <0) { 
		printf (" Can not read from file!");
		return -1;
}
	printf("Let me know the name you want to search:"); 
	gets(name);
	irc = BinarySearch(phonearr, name,n);
	if (irc <0) { 
		printf (" No contact match the criteria!"; 
		return -1;
}
// write result to outputfile
if ((fpout = fopen("result.txt","w")) == NULL){
	printf("Can create file to write.\n");
	reval = FAIL;
}
else 
	fprintf(fpout, "%s have the email address %s and 
	telephone number:%s", phonearr[i].name, 
	phonearr[i].email, phonearr[i].tel);
	fclose(fpout);
	return reval;
}
