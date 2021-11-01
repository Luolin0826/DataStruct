#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <stdlib.h>
#include "MGraphFunction.h"

int MaxOutDegree(MGraph* G) {
	int i, j, OutDegree, max = 0;
	for (i = 0; i < G->VertexNum; i++)
	{
		OutDegree = 0;
		for (j = 0; j < G->VertexNum; j++)
		{
			if (G->arcs[i][j] != 0)
			{
				OutDegree++;
				if (OutDegree > max)
				{
					max = OutDegree;
				}
			}
		}
	}
	return max;
}

int main(int argc, char** argv)
{
	system("pause");
	return 0;
}