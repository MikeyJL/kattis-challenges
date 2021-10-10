/**
 * Island hopping Kattis challenge: https://open.kattis.com/problems/islandhopping
 * @author Mikey Lau (GitHub: MikeyJL)
 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

struct coord { double x, y; };
struct bridge { int start, end; double length; };

/**
 * Used in the qsort to organise by bridge length.
 * @param thisBridge The bridge to compare to the other.
 * @param otherBridge The other bridge to compare.
 * @return -1 if thisBridge is longer, 0 if both bridges are the same, and 1 if otherBridge is longer.
 */
int comparator (struct bridge* thisBridge, struct bridge* otherBridge)
{
    double val = thisBridge->length - otherBridge->length;
    return val < 0 ? -1 : val > 0 ? 1 : 0;
}

/**
 * Finds and returns the index of used coordinates;
 * @param i The coordinate index in question.
 * @param used Pointer to the used array.
 * @return the index postion of the coordinate index in the used array.
 */
int find(int i, int* used)
{
    if (used[i] == i) return i;
    used[i] = find(used[i], used);
    return used[i];
}

int main()
{
    int cases;
    scanf("%d",&cases); // Gets the first line value (number of cases)

    while (cases--)
    {
        int nCoords;
        scanf("%d", &nCoords); // Gets the number of coordinates in the case
        struct coord coordinates[nCoords]; // Inits the coordinates array with the number of coordinates
        
        // Scans line-by-line for floats coordinates and sets to coord array.
        for (int lineIdx = 0; lineIdx < nCoords; lineIdx++) scanf("%lf %lf", &coordinates[lineIdx].x, &coordinates[lineIdx].y);

        int nBridges = (nCoords * (nCoords - 1)) >> 1; // Formula for nth triangular number using bit-shift
        struct bridge bridges[nBridges]; // Inits the array with the number of bridges
        int index = 0;

        // Iterates through the coordinates to represent the starting island/node.
        for (int x = 0; x < nCoords; x++)
        {
            // Iterates through the coordinates to represent the ending island/node.
            for (int y = x + 1; y < nCoords; y++)
            {
                // Sets starting and ending island indices
                bridges[index].start = x;
                bridges[index].end = y;

                // Calculates differences between x and y coordinates.
                double diff_x = coordinates[x].x - coordinates[y].x;
                double diff_y = coordinates[x].y - coordinates[y].y;

                // Pythagoras' theorum to calculate distance.
                bridges[index++].length = sqrt(diff_x * diff_x + diff_y * diff_y);
            }
        }

        index = 0;
        int used[nCoords];
        int connectedBridges = 0;
        double totalDistance = 0.0;

        qsort(bridges, (size_t) nBridges, sizeof(struct bridge), comparator); // Sorts the array

        // Inits array to connected bridges; the index of used is the starting coord; the value of used is the ending coord.
        for (int i = 0; i < nCoords; i++) used[i] = i;

        /**
         * Iterates until all number of connect bridges is equal to 1 less than the number of islands
         * If the index of the coordinates has already been used, then it skips
         * If not used, then the used array will be updated.
         */
        while (connectedBridges < nCoords - 1)
        {
            int start = bridges[index].start;
            int end = bridges[index].end;
            if (!(find(start, used) == find(end, used)))
            {
                totalDistance += bridges[index].length;
                used[find(start, used)] = find(end, used);
                connectedBridges++;
            }
            index++;
        }

        printf("%.6lf\n", totalDistance); // Output
    }
    return 0;
}