#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
#define max 20
#define MAX 5
int adj[max][max];
int n;
int d[100]; //it has times which're achieving to node
int s[100]; //it has times which're processing node
int m=1;
int time=0; 

struct Vertex {  
   char label;
   bool visited;
};

//stack variables

int stack[MAX]; 
int top = -1; 

//graph variables

//array of vertices
struct Vertex* lstVertices[MAX];

//adjacency matrix
int adjMatrix[MAX][MAX];

//vertex count
int vertexCount = 0;

//stack functions

void push(int item) { 
   stack[++top] = item; 
} 

int pop() { 
   return stack[top--]; 
} 

int peek() {
   return stack[top];
}

bool isStackEmpty() {
   return top == -1;
}

//graph functions

//add vertex to the vertex list
void addVertex(char label) {
   struct Vertex* vertex = (struct Vertex*) malloc(sizeof(struct Vertex));
   vertex->label = label;  
   vertex->visited = false;     
   lstVertices[vertexCount++] = vertex;
}

//add edge to edge array
void addEdge(int start,int end) {
   adjMatrix[start][end] = 1;
   adjMatrix[end][start] = 1;
}

//display the vertex
void displayVertex(int vertexIndex) {
   printf("%c ",lstVertices[vertexIndex]->label);
}       

//get the adjacent unvisited vertex
int getAdjUnvisitedVertex(int vertexIndex) {
   int i;

   for(i = 0; i < vertexCount; i++) {
      if(adjMatrix[vertexIndex][i] == 1 && lstVertices[i]->visited == false) {
         return i;
      }
   }

   return -1;
}

int  depthFirstSearch() {
   int i;

   //mark first node as visited
   lstVertices[0]->visited = true;
   d[0]=time++;

   //display the vertex
   displayVertex(0);   

   //push vertex index in stack
   push(0);

   while(!isStackEmpty()) {
      //get the unvisited vertex of vertex which is at top of the stack
      int unvisitedVertex = getAdjUnvisitedVertex(peek());

      //no adjacent vertex found
      if(unvisitedVertex == -1) {
         pop();
      } else {
         lstVertices[unvisitedVertex]->visited = true;
         d[m]=time++;
         m++;
         displayVertex(unvisitedVertex);
         push(unvisitedVertex);
         
         
         
      }
   }

   //stack is empty, search is complete, reset the visited flag        
   for(i = 0;i < vertexCount;i++) {
      lstVertices[i]->visited = false;
      s[i]=time++;
   }        
}

			  
int main(){

	int i, origin, destin,totally_edges=0;
	int option;
	int node;
	
	


	int max_edges=20; // number of edge as much as it can be
	

		
		// In this stage , I inputed number defaultly on given format in the homework.
        origin =1;
		destin=2;
		adj[origin][destin] = 1;
		totally_edges++;
		 
		origin =1;
		destin=4;
		adj[origin][destin] = 1;
		totally_edges++;
		 
		origin =2;
		destin=1;
		adj[origin][destin] = 1;
		
		 
		origin =2;
		destin=3;
		adj[origin][destin] = 1;
		totally_edges++;
		 
		origin =4;
		destin=3;
		adj[origin][destin] = 1;
		
		totally_edges++;
       
        origin =4;
		destin=5;
		adj[origin][destin] = 1;
		 
		 totally_edges++;
		 
		origin =5;
		destin=4;
		adj[origin][destin] = 1;
			
			
			printf("Welcome to Application ,\n ");// Start to Application
     while(1){
	 	
	 		
	 		printf("\n\n\nPlase,Choose to what you want to do\n\n");
	 		
	 		printf("1) Build graph and write in txt file\n");
	 		printf("2) Print to display after calculate your wanted node degree of input and output\n");
	 		printf("3) Calculate to totaly number of edges in Graph\n");
	 		printf("4) Depth first Search\n");
	 		printf("5) EXIT\n");
	 		scanf("%d",&option); 
	 		printf("###################################################################################\n\n\n");
	 		
	 		switch(option){
	 			
	 		case 1:
	 			{
				 
	 			FILE *fp=fopen("Graph.txt","w"); // make a file called Graph.txt
	 			
	 			if(fp==NULL){//if it wouldn't make
	 				printf("ERROR!!!");
				 	exit(1);
				 }
				 
	 			
	 			 for (i = 1; i <= 5; i++) {
       				 for (int j = 1; j <= 5; j++){
		
            			fprintf(fp,"%4d\t", adj[i][j]); // in here , we write in file  made 2D matris.
       		
													}
						fprintf(fp,"\n");
   				 }
   				 fclose(fp);
   				 printf(">>>>>>The File 's called Graph.txt built succesfully  then write in <<<<<<<"); // after wrote , message will came as this
				 break;
	 		}
	 		
	 		case 2:
	 			
	 			{
	 				int input_degree=0;
					int output_degree=0;
	 				
	 				printf("Please , input number of node which's you want to know that input degree and output degree '\n");//In this stage , We can find that input/output degree of our inputed node
					scanf("%d",&node);		
						
					origin =1;
					destin=2;
					adj[origin][destin] = 1;
		
					if(node==origin || node == destin){
	 
        				if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
													}
		
					origin =1;
					destin=4;
					adj[origin][destin] = 1;
					
					if(node==origin || node == destin){
	 
        				if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
													}
	
					origin =2;
					destin=1;
					adj[origin][destin] = 1;
	
					if(node==origin || node == destin){
						if(node==origin)
							input_degree++;
					
						else if(node==destin)
							output_degree++;
					
														}
		
					origin =2;
					destin=3;
					adj[origin][destin] = 1;
					
					if(node==origin || node == destin){
						if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
														}
				
					origin =4;
					destin=3;
					adj[origin][destin] = 1;
					
					if(node==origin || node == destin){
						if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
														}
	
					origin =4;
					destin=5;
					adj[origin][destin] = 1;
				
					if(node==origin || node == destin){
						if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
													}
	
	
					origin =5;
					destin=4;
					adj[origin][destin] = 1;
					
					if(node==origin || node == destin){
						if(node==origin)
							input_degree++;
						else if(node==destin)
							output_degree++;
													}
	
	
				if(input_degree==0 && output_degree==0){ // if our variables (Ýnput/output degree) 're equal to 0 ,which mean either there's no inputed node or stayed alone.
					printf("There's no node that you inputted'");
				}
				else{
					
					printf("Your Node's input degree's %d\n",input_degree);
					printf("Your Node's output degree's %d\n",output_degree);
					
				}
	
	
	 				break;
				 }
	 		case 3:	
	 		printf("Totally Number of edges're %d",totally_edges);   // print to display that totaly number of edges
	 		break;
	 		
	 		case 4 :
	 			
	 		{
			 // In this stage  , we walk all node through Depth first Search algorithm . 

   for(int i = 0; i < MAX; i++) {   // set adjacency {
      for(int j = 0; j < MAX; j++) // matrix to 0
         adjMatrix[i][j] = 0;
   }
 
   addVertex('A');   // 0
   addVertex('B');   // 1
   addVertex('C');   // 2
   addVertex('D');   // 3
   addVertex('E');   // 4

   addEdge(0, 1);    // A - B
   addEdge(0, 3);    // A - D
   addEdge(1, 0);    // B - A
   addEdge(1, 2);    // B - C
   addEdge(3, 2);    // D - C
   addEdge(3, 4);    // D - E
   addEdge(4, 3);    // E - D
   printf("Depth First Search: ");
   depthFirstSearch();
   printf("\n\n\nACHIEVING TIME\n"); 
   for (int l=0;l<5;l++){
   	printf("%d\n",d[l]);
   }
   printf("\n\n\nPROCESSING TIME\n"); 
     for (int r=0;r<5;r++){
   	printf("%d\n",s[r]);
   }

   break; 

		}
	 		
	 		case 5:
	 			printf("GOOD BYE :D:D:D");//In this stage, exit.
	 			exit(1);
	 			
			 }
	 		
	 		
    
    
    
		
		
		
		}
    
    
    
    
    
	}
	
	
	

