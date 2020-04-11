
#include <stdio.h>
#include <stdlib.h>
double PFRate();
void userInput(void);

double PFempty;
double PFmodified;
double access_time;
double timesPFmodified;
double eff_access_time;
double pagefRate;
double PFempty_ns;
double PFmodified_ns;
double timesPFmodified_per;
	

void main(){
	int swch;
	
	do{
	
	
	printf("Select the required option \n");
	printf("1.Find the PageFault Rate\n");
	printf("2.Exit");
	scanf("%d",&swch);
	switch(swch){
		case 1:userInput();break;
		case 2:exit(0);
	}
	printf("\n\n");

}while(swch<3);
}
void userInput(){
	
	
	printf("\nEnter service Page Fault [Empty|Page is not Modified][in milliseconds]");
	scanf("%lf",&PFempty);
	printf("Enter Service Page Fault [Modified Page][in milliseconds]");
	scanf("%lf",&PFmodified);
	printf("Enter Memory Access Time[in nanoseconds]");
	scanf("%lf",&access_time);
	printf("Enter Percentage of time the page to be replaced is modified[0-100]");
	scanf("%lf",&timesPFmodified);
	printf("Enter Effective Access time[in nanoseconds]");
	scanf("%lf",&eff_access_time);

	PFempty_ns = (PFempty*1000000);
	PFmodified_ns = (PFmodified*1000000);
	timesPFmodified_per = (timesPFmodified/100);   
	printf("\nPage Fault rate calculated For:\n");
	printf("Service Page Fault[Empty|Page Not Modified]=%lf \n",PFempty_ns);
	printf("Service Page Fault [Modified Page][in nanoseconds] %lf \n",PFmodified_ns);
	printf("Memory Access Time[in nanoseconds]%lf\n",access_time);
	printf("Effective Access Time %lf\n",eff_access_time);
    pagefRate =  PFRate(PFempty_ns,PFmodified_ns,access_time,timesPFmodified_per,eff_access_time);
	printf("\nMaximum Acceptable Page Fault rate = %.2e[exponential notation]",pagefRate);
}

double PFRate(double servicePageFaultEmpty,double servicePageFaultMod,double memAccess,double timesPages,double effAccess){
	double assume,serve;
	double num,den;
	double pageFault;
	 assume = (1- timesPages)*servicePageFaultEmpty;
	 serve = timesPages*servicePageFaultMod;
	 num = effAccess - memAccess;
     den = (assume+serve);

	pageFault = num/den;
	return pageFault;


}

