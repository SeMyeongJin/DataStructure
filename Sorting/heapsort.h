#pragma once

/*
히프 자료구조를 이용하여 자료를 정렬합니다
히프는 완전 이진 트리이면서 동시에 최대 트리 혹은 최소 트리입니다.
오름차순으로 정렬하고 싶은 경우 최소 히프에서 개수만큼 루트 노드를 삭제합니다.
내림차순은 반대로 최대 히프에서 개수만큼 루트 노드를 삭제하여 정렬합니다.
*/

void heapSort(int value[], int count)
{
	int i = 0;
	ArrayMinHeap* pHeap = NULL;

	pHeap = createArrayMinHeap(count);
	if (pHeap != NULL)
	{
		HeapNode node;
		for (i = 0; i < count; i++)
		{
			node.key = value[i];
			insertMinHeapAH(pHeap, node);
		}
		for (i = 0; i < count; i++)
		{
			HeapNode* pNode = deleteMinHeapAH(pHeap);
			if (pNode != NULL)
			{
				value[i] = pNode->key;
				free(pNode);
			}
		}

		deleteArrayMinHeap(pHeap);
	}
}