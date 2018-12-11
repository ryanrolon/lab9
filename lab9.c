#include <stdio.h>
#include <stdlib.h>

#define LIMIT_TO_READING_LINES 8
#define QUESTIONS_ASKED 11
#define LIMIT_TO_READING_ANSWERKEY 1

typedef struct { char first[10]; } firstname_t;
typedef struct { char last[10]; } lastname_t;

void processdata( );

int main( )
{
	processdata( );
}



void processdata( ) 
{
	int count; count = 0; 
	int id;
	int i;
	char key[QUESTIONS_ASKED];
	char selection[LIMIT_TO_READING_LINES][QUESTIONS_ASKED];
	int identities[LIMIT_TO_READING_LINES];
	firstname_t firstname[100];
	lastname_t lastname[100];
	double gradecalc = 0.0;
	double grade[LIMIT_TO_READING_LINES];
	double calc[ LIMIT_TO_READING_LINES];


	FILE * answers = fopen("newomr.txt", "r");
	
	while(fscanf( answers, "%d", &id) == 1){
	
		count++;	

		for( i = 0; i < QUESTIONS_ASKED ; i++ ){
		fscanf( answers, "%c", &key[ i ] );    } 		
	
	if( count >= LIMIT_TO_READING_ANSWERKEY )
	break;					}

	count = 0;

	      while ( fscanf( answers, "%d", &id ) == 1 ) {
                count++;
                identities[ count ] = id;
                for ( i = 1; i < QUESTIONS_ASKED + 1; i++ ) {
                fscanf( answers, "%c", &selection[count][i] );
						     }

	if( count >= LIMIT_TO_READING_LINES)
	break;					}
	
	count = 0;

	fclose(answers);

	FILE * names = fopen("testtakernames.txt", "r");

		while(!feof(names))  {
			count++;
			fscanf(names,"%d%s %s", &id, firstname[count].first, lastname[count].last);
		
		if( count >= LIMIT_TO_READING_LINES )
		break;
				    }

	fclose(names);
	count = 0;

	FILE * combined = fopen("full_data.csv", "w");
	fprintf(combined, "IDENTITY, NAME, Q1, Q2, Q3, Q4, Q5, Q6, Q7, Q8, Q9, Q10, Q11\n");

	while( count < LIMIT_TO_READING_LINES ){
		fprintf(combined, "%5.5d, %s %s", identities[count + 1], firstname[count + 1].first, lastname[count + 1].last );
		for(i = 0; i < QUESTIONS_ASKED; i++ ){
		fprintf(combined, ", %c", selection[ count + 1 ][ i + 1 ] );
						     }
		fprintf(combined, "\n");
		count++;		       }
	
	fclose(combined);

	return;
}
