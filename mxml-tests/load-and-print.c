#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <mxml.h>

int main(int argc, char *argv[])
{
	FILE *fp;
	mxml_node_t *tree=NULL;
	mxml_node_t *node=NULL;
	const char *value=NULL;

	if ( argc < 2 )
	{
		printf("error: the app needs one parameter, a xml file\n");
		return EXIT_FAILURE;
	}
	fp = fopen(argv[1], "r");
	tree = mxmlLoadFile(NULL, fp, MXML_OPAQUE_CALLBACK);
	
	node = mxmlWalkNext(tree, tree, MXML_DESCEND);
	while ( node != NULL)
	{
		if ( node->type == MXML_CUSTOM )
			printf ("typo custom\n");
		if ( node->type == MXML_ELEMENT )
		{
			printf ("%-14s: %-25s cant attr:  %d\n","typo element",node->value.element.name,node->value.element.num_attrs);
			if ( node->value.element.num_attrs > 0 )
			{
				value = mxmlElementGetAttr(node, "value");
				printf ("*%44svalue: %10s\n","",value);

			}
		}
		if ( node->type == MXML_INTEGER )
			printf ("typo integer\n");
		if ( node->type == MXML_OPAQUE )
		{
			if (node->value.opaque[0] != '\n' )
				printf ("%-14s: %-25s\n","typo opaque",node->value.opaque);

		}
		if ( node->type == MXML_REAL )
			printf ("typo real\n");
		if ( node->type == MXML_TEXT )
		{
			if ( strcmp(node->value.text.string,"") != 0 )
			{
				printf ("%-14s: %-25s whitespace? %d\n","typo text",node->value.text.string,node->value.text.whitespace);
			}
		}

		node = mxmlWalkNext(node, tree, MXML_DESCEND); /*needed to advance*/
	}


	fclose(fp);
	return 0;
} 
