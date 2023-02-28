#include <stdio.h>
#include <stdlib.h>
#include "tlist.h"

TREE buildTree (int n) {

	TREE root = NULL;
	int ndLeft, ndRight;
	
	if (n>0) {
		ndRight = n / 2;
		ndLeft = n - ndRight - 1;
		root = (TREE) malloc (sizeof (NODE));
		root->key = n;
		root->left = buildTree (ndLeft);
		root->right = buildTree (ndRight);
	}
	return root;
}

void printTree (TREE root, int layer) {

	int i, counter = 0;

	if (root != NULL) {
		printTree (root->left, layer + 1);
		for (i = 0; i<layer; i++) {
			printf ("   ");
		}
		printf ("%d\n", root->key);
		printTree (root->right, layer + 1);
	}
}

TREE buildTreeByFormula (char* formula) {
	int i = 0;
	while (formula [i] != '\0') i++;
	return buildTreeByFormulaRec (formula, 0, i - 1);
}

TREE buildTreeByFormulaRec (char* formula, int s, int e) {
	TREE t = NULL;
	int i = s
		, bracketLevel = 0
		, lastLowRangOp = -1
		, lastHightRangOp = -1;
	char symb = formula [i];
	if (s == e) {
		t = (TREE) malloc (sizeof (NODE));
		t->key = symb;
		t->left = NULL;
		t->right = NULL;
		return t;
	}
	while (i <= e) {
		if (symb == '(') {
			bracketLevel++;
		}
		else if (symb == ')') {
			bracketLevel--;
		}
		else if ((symb == '+' || s == '-') && bracketLevel == 0) {
			lastLowRangOp = i;
		}
		else if ((symb == '*' || s == '/') && bracketLevel == 0) {
			lastHightRangOp = i;
		}
		else if (bracketLevel == 0 && symb<'0' && symb>'9') {
			printf ("ERR! UNEXP SYMB '%c' AT %d\n", symb, i);
		}
		i++;
		symb = formula [i];
	}
	if (lastLowRangOp != -1) {
		t = (TREE) malloc (sizeof (NODE));
		t->key = formula [lastLowRangOp];
		t->left = buildTreeByFormulaRec (formula, s, lastLowRangOp - 1);
		t->right = buildTreeByFormulaRec (formula, lastLowRangOp + 1, e);
	}
	else if (lastHightRangOp != -1) {
		t = (TREE) malloc (sizeof (NODE));
		t->key = formula [lastHightRangOp];
		t->left = buildTreeByFormulaRec (formula, s, lastHightRangOp - 1);
		t->right = buildTreeByFormulaRec (formula, lastHightRangOp + 1, e);
	}
	else {
		return buildTreeByFormulaRec (formula, s + 1, e - 1);
	}

	return t;
}

char* buildFormulaByTree (TREE t, char* formula) {
	int i = 0;
	buildFormulaByTreeRec (t, formula);
	formula [i] = '\0';
	return formula;
}

void buildFormulaByTreeRec (TREE t, char* formula) {
	int i;
	if (t != NULL) {
		formula [i++] = t->key;
		buildFormulaByTreeRec (t->left, formula);
		buildFormulaByTreeRec (t->right, formula);
	}
}