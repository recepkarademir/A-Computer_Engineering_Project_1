#include<iostream>
int main()
{
	int N2A,alt,bitir=0,N;
	std::cout<<"N : ";
	std::cin>>N;
	alt=2*N;
	while(bitir!=1)
	{
		for(int knt=2;knt<alt;knt++)
        {
            if(alt%knt==0)
            {
            	break;
			}
            else if(alt==knt+1)
            {
            	N2A=alt; // N2A deðiþkeni asal sayýmýz 211
            	bitir=1;
			}
        }
		++alt;
	}
	std::cout<<"\nN2A : "<<N2A<<std::endl;
	return 0;
}
