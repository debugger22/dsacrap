/*
Consider a student database, where each student record contains student name and their total mark obtained in a particular subject. It is decided that the whole database will be divided into different groups and the topper will be found out from the respective groups who have highest mark in their group. For this, name (unique) of the students are decided as the key. Implement this using hashing .To handle collision (if any), use open addressing with chaining. Under this scheme, if two names collide (say `Y'  collides with the existing name ‘X’), then ‘Y’ should belongs to the group of ‘X’ and ‘X’ should contain address of ‘Y’. Similarly if `Z' collide with either `X' or `Y', it will be stored at the end of the list(`X '→`Y' →`Z') and so on. If ‘Y’ (new element) does not collide with any element, then it will form a new group, with ‘Y’ as the first element of the group. When the table is full then you have to rehash the elements to the new hash table, double the size of old hash table. Students in a group should not be changed while rehashing.

(Note: 
1. Use the hash function ((h’(x)) as described below:-
The weightage for character `A' or `a' as 1, `B' or `b' as 2 and so on. Name should consisting of alphabets (A | a – Z | z) only.
The hash function h’(x) = hash (key) = (int(key))modulus m, where `m' is number of cells in the hash table. Example: hash (Amar) = (1+13+1+18) modulus m.

2. Use linear probing mechanism for open addressing (h(x) = ((h’(x) + i) mod m)
    where i=0,1,2……,m and m is the number of slots.

INPUT FORMAT
<M>
<N>
<Name of student 1>
<Marks of Student 1>
.
.
<Name of student N>
<Marks of Student N>
OUTPUT FORMAT
<Total Groups G>
<Group 1><Topper Name><Marks>
<Group 2><Topper Name><Marks>
.
.
<Group G><Topper Name><Marks>

TestCases
......................................................................
Input.in
2
5
Shail
45
zuri
68
malti
68
Swati
78
kelvin
55

Output.out
GROUP:1 TOPPER: Swati MARKS: 78.000000
GROUP:2 TOPPER: kelvin MARKS: 55.000000
GROUP:3 TOPPER: zuri MARKS: 68.000000
GROUP:4 TOPPER: malti MARKS: 68.000000
......................................................................
Input.in
3
8
Nikita
45
Ankita
68
Mahesh
68
Harsh
78
Tanu
55
Arundhati
77
Kailash
98
Aastha
100

Output.out
GROUP:1 TOPPER: Kailash MARKS: 98.000000
GROUP:2 TOPPER: Aastha MARKS: 100.000000
GROUP:3 TOPPER: Nikita MARKS: 45.000000
GROUP:4 TOPPER: Harsh MARKS: 78.000000
GROUP:5 TOPPER: Ankita MARKS: 68.000000
......................................................................
There can be more efficient way of implementing the soltuion of the given problem statement, this is just one oy of implementing it
*/
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
typedef struct slot
{
	char *name;
	float marks;
	int next_group_member;
	int head;						//head=-1 if it is slot is empty	head=0 if not head	head=1 if head
} slot;

int value(char i)
{
	int d;
	d=i;
	if(d >='a' && d<='z')
		return ((d-'a')+1);
	else
		return ((d-'A')+1);
}

//hash function (as per the definition in the question) will return the home address given the name of the student
int hash_function(char *name,int slots)
{
	int i,total=0,m;
	i=0;
	while(name[i]!='\0')							  
	{
		total+=value(name[i]);
		i++;
	}
	m=(total % slots); 
	return m;	
}

//hash student data in the table according to the rules mentioned
int hash(slot *hash_table,char *name,float marks,int m,int *count)
{
	int hx=0,hx_new=0,j,last_mem=0;

	hx = hash_function(name,m);								//find home address
	if(hash_table[hx].head == -1)								//if slot is empty store value and form new group
	{
		hash_table[hx].name=(char *)malloc(strlen(name)*sizeof(char));
		strcpy(hash_table[hx].name,name);
 		hash_table[hx].marks=marks;
		hash_table[hx].next_group_member=-1;
		hash_table[hx].head=1;
		*count=*count+1;		
	}
	else							//collision find new empty slot and add student to the group with which it collides
	{
		j=1;
		hx_new=(hx+j)%m;
		while((hash_table[hx_new].head!=-1 || (hx_new==hx)) && *count!=m)		//finding new hash value
		{
			hx_new=(hx+j)%m;
			j++;			
		}

		*count=*count+1;
		last_mem=hx;							//remember member with which collision occured
		if(*count<=m)
		{
			while(hash_table[last_mem].next_group_member!=-1)
			{
				last_mem=hash_table[last_mem].next_group_member;	//chaining new member to the group
			}
			hash_table[last_mem].next_group_member=hx_new;

			hash_table[hx_new].name=(char *)malloc(strlen(name)*sizeof(char));	//hashing new data
			strcpy(hash_table[hx_new].name,name);
	 		hash_table[hx_new].marks=marks;
			hash_table[hx_new].next_group_member=-1;
			hash_table[hx_new].head=0;							
		}
		else
		{	
			return -1;
		}
	}
	return 1;
}

slot* rehash(slot *hash_table,int *m)
{
	int new_size,i,hx=0,k=0,hx_new=0,j=0,last_mem=0,flag=0;
	slot *new_hash;
	new_size=2*(*m);						//new_hashtable_size=2*old_hashtable_size
	new_hash=(slot *)malloc(new_size*sizeof(slot));			//allocate memory
	for(i=0;i<new_size;i++)
	{
		new_hash[i].head=-1;
	}
	for(i=0;i<*m;i++)						//rehash values of old hash table such that group don't change
	{
		j=0;
		if(hash_table[i].head==1)
		{
			j=i;
			flag=0;
			while(flag!=1)					//rehashing values for one group at a time
			{
				hx = hash_function(hash_table[j].name,new_size);
				if(new_hash[hx].head == -1)
				{
					new_hash[hx].name=(char *)malloc(strlen(hash_table[j].name)*sizeof(char));
					strcpy(new_hash[hx].name,hash_table[j].name);
			 		new_hash[hx].marks=hash_table[j].marks;
					new_hash[hx].next_group_member=-1;
					if(j==i)
						new_hash[hx].head=1;
					else
						new_hash[hx].head=0;	
				}
				else
				{
					k=1;
					hx_new=(hx+k)%new_size;
					while((new_hash[hx_new].head!=-1 || (hx_new==hx)))
					{
						hx_new=(hx+k)%new_size;
						k++;			
					}
					last_mem=hx;
					while(new_hash[last_mem].next_group_member!=-1)
					{
						last_mem=new_hash[last_mem].next_group_member;
					}
					new_hash[last_mem].next_group_member=hx_new;
					new_hash[hx_new].name=(char *)malloc(strlen(hash_table[j].name)*sizeof(char));
					strcpy(new_hash[hx_new].name,hash_table[j].name);
			 		new_hash[hx_new].marks=hash_table[j].marks;
					new_hash[hx_new].next_group_member=-1;
					if(j==i)
						new_hash[hx_new].head=1;
					else
						new_hash[hx_new].head=0;
				}
				j=hash_table[j].next_group_member;
				if(j==-1)
					flag=1;
			}
		}
	}
	hash_table=(slot *)realloc(hash_table,new_size*sizeof(slot));			//reallocating memeory for the table
	for(i=0;i<new_size;i++)
	{
		if(new_hash[i].head!=-1)						//copying data
		{
			hash_table[i].name=(char *)malloc(strlen(new_hash[i].name)*sizeof(char));
			strcpy(hash_table[i].name,new_hash[i].name);
			hash_table[i].marks=new_hash[i].marks;
			hash_table[i].next_group_member=new_hash[i].next_group_member;
			hash_table[i].head=new_hash[i].head;
		}
		else
		{
			hash_table[i].name=NULL;
			hash_table[i].marks=0;
			hash_table[i].next_group_member=0;
			hash_table[i].head=-1;
		}
		
	}
	*m=new_size;
	return hash_table ;
}

int main(void)
{
	int m=0,i,n,j,hx = 0,hx_new=0,flag,check=0,max,group;
	int count=0;
	char *name,ch;
	float marks;
	slot *hash_table;
		
	//Taking input
	scanf("%d",&m);								//Initial number the slots in the hash table

	hash_table=(slot *)malloc(m*sizeof(slot));				//allocating memory for the m number of slots
	for(i=0;i<m;i++)		
	{
		hash_table[i].head=-1;
	}

	scanf("%d",&n);								//Number of students

	//read name and marks of students and hash it into the table...
	for(i=0;i<n;i++)
	{
		printf("name:");
		scanf("%s",name);
		printf("marks:");
		scanf("%f",&marks);

		if(count<m)
			check=hash(hash_table,name,marks,m,&count);
//if number of slots are less than the number of students,rehash values with new_hashtable_size=2*old hash_table_size such that already formed group should not be changed.
		else						
		{
			/*// Values in hashtable before rehashing
			for(j=0;j<m;j++)
				printf("\nname=%s marks=%f nextgroup_member=%d head=%d index=%d",hash_table[j].name,hash_table[j].marks,hash_table[j].next_group_member,hash_table[j].head,j);
			printf("\n....REHASH.....");
			*/
			hash_table=rehash(hash_table,&m);
			check=hash(hash_table,name,marks,m,&count);
		}		
	}
	/*//Final hash table
	for(j=0;j<m;j++)
		printf("\nname=%s marks=%f nextgroup_member=%d head=%d index=%d",hash_table[j].name,hash_table[j].marks,hash_table[j].next_group_member,hash_table[j].head,j);
	*/
	group=0;
	for(j=0;j<m;j++)
	{
		max=0;
		if(hash_table[j].head==1)
		{
			flag=0;
			max=j;
			i=j;
			do
			{
				if(hash_table[max].marks<hash_table[i].marks)
					max=i;
				if(hash_table[i].next_group_member==-1)
					flag=1;
				else
					i=hash_table[i].next_group_member;
			}while(flag==0);
			group++;
			printf("\nGROUP:%d TOPPER: %s MARKS: %f",group,hash_table[max].name,hash_table[max].marks);
		}		
	}
	return 0;
}

