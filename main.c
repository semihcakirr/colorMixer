#include <stdio.h>
#include <stdlib.h>
#include <math.h>
// Enumeration type for colors.
typedef enum
{
    RED,
    GREEN,
    BLUE,
    YELLOW,
    ORANGE
} Color;
// 2D array containing the length-3 vectors of each color.
double colors[][3] = {
    {1, 0, 0},
    {0, 1, 0},
    {0, 0, 1},
    {0.5, 0.5, 0},
    {0.5, 0.4, 0.2}};
// Function to calculate the Euclidean distance between two colors.
double distance(double *c1, double *c2)
{
    double d1 = c1[0] - c2[0];
    double d2 = c1[1] - c2[1];
    double d3 = c1[2] - c2[2];
    return sqrt(d1 * d1 + d2 * d2 + d3 * d3);
}
// Function to mix two colors and return the closest color based on Euclidean distance.
Color mixColors(Color c1, Color c2)
{
    // Calculate the mixed color as the average of the length-3 vectors of the input colors.
    double mixed[3];
    for (int i = 0; i < 3; i++)
    {
        mixed[i] = (colors[c1][i] + colors[c2][i]) / 2;
    }
    // Find the color with the minimum Euclidean distance to the mixed color.
    double minDist = INFINITY;
    Color result = RED;

    for (int i = 0; i < 5; i++)
    {
        double d = distance(mixed, colors[i]);
        if (d < minDist)
        {
            minDist = d;
            result = (Color)i;
        }
    }

    return result;
}
// Function to mix two colors and print the result.
void colorMixer(Color c1, Color c2, Color (*mixer)(Color, Color))
{
    // Call the function pointer with the input colors to mix them.
    Color mixedColor = (*mixer)(c1, c2);
    // Get the length-3 vector of the mixed color
    double *mixedValues = colors[mixedColor];
    // Print the mixed color with its name and length-3 vector.
    printf("Mixed Color: ");
    switch (mixedColor)
    {
    case RED:
        printf("RED ");
        break;
    case GREEN:
        printf("GREEN ");
        break;
    case BLUE:
        printf("BLUE ");
        break;
    case YELLOW:
        printf("YELLOW ");
        break;
    case ORANGE:
        printf("ORANGE ");
        break;
    }
    printf("[%.1f, %.1f, %.1f]\n", mixedValues[0], mixedValues[1], mixedValues[2]);
}

int main()
{
    char c1, c2;
    printf("Enter Color 1 (r,g,b,y,o): ");
    Color color1, color2;
    do
    {
        // Get user input for the two colors to mix.
        scanf(" %c", &c1);
        if (c1 == 'r')
        {
            color1 = RED;
        }
        else if (c1 == 'g')
        {
            color1 = GREEN;
        }
        else if (c1 == 'b')
        {
            color1 = BLUE;
        }
        else if (c1 == 'y')
        {
            color1 = YELLOW;
        }
        else if (c1 == 'o')
        {
            color1 = ORANGE;
        }
        else
        {
            printf("Invalid input!\n");
            printf("Enter a valid input(r,g,b,y,o): ");
        }
        getchar(); // consume newline
    } while ((c1 != 'r') && (c1 != 'g') && (c1 != 'b') && (c1 != 'y') && (c1 != 'o'));

    printf("Enter Color 2 (r,g,b,y,o): ");
    do
    {
        scanf(" %c", &c2);
        if (c2 == 'r')
        {
            color2 = RED;
        }
        else if (c2 == 'g')
        {
            color2 = GREEN;
        }
        else if (c2 == 'b')
        {
            color2 = BLUE;
        }
        else if (c2 == 'y')
        {
            color2 = YELLOW;
        }
        else if (c2 == 'o')
        {
            color2 = ORANGE;
        }
        else
        {
            printf("Invalid input!\n");
            printf("Enter a valid input(r,g,b,y,o): ");
        }
    } while ((c2 != 'r') && (c2 != 'g') && (c2 != 'b') && (c2 != 'y') && (c2 != 'o'));

    colorMixer(color1, color2, mixColors);

    return 0;
}