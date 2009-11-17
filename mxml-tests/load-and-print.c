#include <mxml.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void)
{
	FILE *fp;
	mxml_node_t *tree=NULL;
	mxml_node_t *node=NULL;

	fp = fopen("example.xml", "r");
	tree = mxmlLoadFile(NULL, fp, MXML_TEXT_CALLBACK);
	
	node = mxmlWalkNext(tree, tree, MXML_DESCEND);
	while ( node != NULL)
	{
		printf("type: %d\tname %s\n",node->type,node->value.text.string);
		node = mxmlWalkNext(node, tree, MXML_DESCEND);
	}


	fclose(fp);
	return 0;
} 
