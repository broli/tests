#include <mxml.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const char *whitespace_cb(mxml_node_t *node, int where)
{
	const char *name;
	const char *Parname;
	name = node->value.element.name;
	
	if (where == 1 && strcmp(name, "?xml version=\"1.0\"?") == 0)
		return "\n";
	if (where == 1 && strcmp(name, "data") == 0)
		return "\n";
	if ( (where == 1 || where == 3) && strcmp(name, "group") == 0)
		return "\n";
	if ( (where == 0 || where == 2) && strcmp(name, "group") == 0)
		return "\t\t";
	if ( (where == 0 || where == 2) && strcmp(name, "data") == 0)
		return "\t";
	if (where == 3 && strcmp(name, "node") == 0)
		return "\n";
	if (where == 0 && strcmp(name, "node") == 0)
	{
		Parname = node->parent->value.element.name;
		if ( strcmp(Parname, "group") == 0 )
			return "\t\t\t";

		return "\t\t";
	}


	return NULL;
}

int main(void)
{
    mxml_node_t *xml;    /* <?xml ... ?> */
    mxml_node_t *data;   /* <data> */
    mxml_node_t *node;   /* <node> */
    mxml_node_t *group;  /* <group> */
    FILE *fp;

    xml = mxmlNewXML("1.0");

    data = mxmlNewElement(xml, "data");

        node = mxmlNewElement(data, "node");
        mxmlNewText(node, 0, "val1");
        node = mxmlNewElement(data, "node");
        mxmlNewText(node, 0, "val2");
        node = mxmlNewElement(data, "node");
        mxmlNewText(node, 0, "val3");

        group = mxmlNewElement(data, "group");

            node = mxmlNewElement(group, "node");
            mxmlNewText(node, 0, "val4");
            node = mxmlNewElement(group, "node");
            mxmlNewText(node, 0, "val5");
            node = mxmlNewElement(group, "node");
            mxmlNewText(node, 0, "val6");

        node = mxmlNewElement(data, "node");
        mxmlNewText(node, 0, "val7");
        node = mxmlNewElement(data, "node");
        mxmlNewText(node, 0, "val8");

     fp = fopen("filename.xml", "w");
     mxmlSaveFile(xml, fp, whitespace_cb);
     fclose(fp);
     return 0;
} 
