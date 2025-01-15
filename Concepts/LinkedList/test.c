#include <stdio.h>
#include <stdbool.h>

#define MAX 100

// Function to check reflexivity
bool isReflexive(int relation[][2], int n, int elements[], int elem_count) {
    for (int i = 0; i < elem_count; i++) {
        int found = 0;
        for (int j = 0; j < n; j++) {
            if (elements[i] == relation[j][0] && elements[i] == relation[j][1]) {
                found = 1;
                break;
            }
        }
        if (!found) return false;
    }
    return true;
}

//Function to check irreflexive
bool isIrreflexive(int relation[][2],int n,int elements[],int elem_count){
    for(int i=0;i<elem_count;i++)
    {
        for(int j=0;j<n;j++)
        {
            if(elements[i] == relation[j][0] && elements[i] == relation[j][1])
            {
                return false;
            }
        }
    }
    return true;
}

// Function to check symmetry
bool isSymmetric(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0], b = relation[i][1];
        if (a != b) {
            int found = 0;
            for (int j = 0; j < n; j++) {
                if (relation[j][0] == b && relation[j][1] == a) {
                    found = 1;
                    break;
                }
            }
            if (!found) return false;
        }
    }
    return true;
}

//Function to check antisymmetric
bool isAntisymmetric(int relation[][2],int n)
{
for(int i=0;i<n;i++)
{
    int a = relation[i][0],b = relation[i][1];
    if(a!=b)
    {
        for(int j=0;j<n;j++)
        {
            if(relation[j][0] == b && relation[j][1] == a)
            {
                return false;
            }
        }
    }
}
return true;
}

// Function to check transitivity
bool isTransitive(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (relation[i][1] == relation[j][0]) {
                int a = relation[i][0], c = relation[j][1];
                int found = 0;
                for (int k = 0; k < n; k++) {
                    if (relation[k][0] == a && relation[k][1] == c) {
                        found = 1;
                        break;
                    }
                }
                if (!found) return false;
            }
        }
    }
    return true;
}

bool isAsymmetric(int relation[][2], int n) {
    for (int i = 0; i < n; i++) {
        int a = relation[i][0], b = relation[i][1];
        if (a == b) {
            // A relation is not asymmetric if (a, a) exists
            return false;
        }
        for (int j = 0; j < n; j++) {
            if (relation[j][0] == b && relation[j][1] == a) {
                // A relation is not asymmetric if both (a, b) and (b, a) exist
                return false;
            }
        }
    }
    return true;
}

int main() {
    int n, elem_count, elements[MAX], relation[MAX][2];

    printf("Enter the number of elements in the set: ");
    scanf("%d", &elem_count);

    printf("Enter the elements of the set: ");
    for (int i = 0; i < elem_count; i++) {
        scanf("%d", &elements[i]);
    }

    printf("Enter the number of pairs in the relation: ");
    scanf("%d", &n);

    printf("Enter the pairs of the relation (a b):\n");
    for (int i = 0; i < n; i++) {
        scanf("%d %d", &relation[i][0], &relation[i][1]);
    }


// Check properties
    bool reflexive = isReflexive(relation, n, elements, elem_count);
    bool irreflexive = isIrreflexive(relation, n, elements, elem_count);
    bool symmetric = isSymmetric(relation, n);
    bool asymmetric = isAsymmetric(relation, n);
    bool transitive = isTransitive(relation, n);
    bool antisymmetric = isAntisymmetric(relation, n);

    if (reflexive) {
        printf("The relation is Reflexive.\n");
    } else {
        printf("The relation is NOT Reflexive.\n");
    }

    if (irreflexive) {
        printf("The relation is Irreflexive.\n");
    } else {
        printf("The relation is NOT Irreflexive.\n");
    }

    if (symmetric) {
        printf("The relation is Symmetric.\n");
    } else {
        printf("The relation is NOT Symmetric.\n");
    }
    if (asymmetric) {
        printf("The relation is Asymmetric.\n");
    } else {
        printf("The relation is NOT Asymmetric.\n");
    }
    if (antisymmetric) {
        printf("The relation is Antisymmetric.\n");
    } else {
        printf("The relation is NOT Antisymmetric.\n");
    }

    if (transitive) {
        printf("The relation is Transitive.\n");
    } else {
        printf("The relation is NOT Transitive.\n");
    }

    

    // Check equivalence relation
    if (reflexive && symmetric && transitive) {
        printf("The relation is an Equivalence Relation.\n");
    } else {
        printf("The relation is NOT an Equivalence Relation.\n");
    }
    return 0;
}