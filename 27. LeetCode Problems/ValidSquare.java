//Created by Mitadru Datta

/*
  Valid Square
  Ref :- https://leetcode.com/problems/valid-square/

  Problem Statement :-
  Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
  The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.

  A valid square has four equal sides with positive length and four equal angles (90-degree angles).

  Constraints:
  p1.length == p2.length == p3.length == p4.length == 2
  -104 <= xi, yi <= 104
 */

/*
  Concepts about square:-

  All sides of a square are equal but all quadrilateral with equal edge length are not square ex, Rhombus
  All the interior angles of a square is 90-degree
  Both the condition of equal sides and all 90-degrees angles must satisfy in order to be declared a square

  Formulae used :-

  To check whether the interior angles is right-angled or not, first find out the edge length as well as the length
  of the diagonal. Then, check whether the edges form a Pythagorean Triplet or not.
  A Pythagorean Triplet satisfies the equation :- (base)^2 + (perpendicular)^2 = (Hypotenuse)^2

  Calculating the edge length:-
  Suppose there are two points A(x1, y1) and B(x2, y2). Now the length of the edge AB can be calculated using the
  formula :-  edge_length = ( (x2 - x1)^2 + (y2 - y1)^2 )^0.5
 */


package com.mitadru;

import java.util.Scanner;

public class Main {

    public static double edgeLength(int[] pointA, int[] pointB, boolean wantSquare) {  // To calculate the length of each edge

        int xDiff = Math.abs(pointB[0] - pointA[0]);
        int yDiff = Math.abs(pointB[1] - pointA[1]);
        if (wantSquare) {
            return (xDiff * xDiff + yDiff * yDiff);  // Return the square of the edge value i.e. (edge)^2
        }
        return Math.sqrt(Math.pow(xDiff, 2) + Math.pow(yDiff, 2));  //Return the edge value
    }

    public static boolean checkAngle(double baseSquare, double perpendicularSquare, double hypotenuseSquare) {
        return (baseSquare + perpendicularSquare) == hypotenuseSquare; // Returns true if the angle is 90-degrees, else false
    }

    public static boolean checkOpposite(int[] opposite, int[] pointC, int[] pointD) { // checks conditions for opposite vertex
        double oppC = edgeLength(opposite, pointC, false);
        double oppD = edgeLength(opposite, pointD, false);

        double oppC2 = edgeLength(opposite, pointC, true);
        double oppD2 = edgeLength(opposite, pointD, true);
        double CD2 = edgeLength(pointC, pointD, true);
        if (oppC != oppD) { // checks that edges emerging from the opposite vertex are equal or not
            return false;
        }
        return checkAngle(oppC2, oppD2, CD2); // checks whether the interior angle of the opposite vertex is 90-degrees or not
    }

    public static boolean validSquare(int[] p1, int[] p2, int[] p3, int[] p4) {

        double p1p2 = edgeLength(p1, p2, false); // p1p2 has the length value of the edge between points p1 and p2
        double p1p3 = edgeLength(p1, p3, false); // p1p3 has the length value of the edge between points p1 and p3
        double p1p4 = edgeLength(p1, p4, false); // p1p4 has the length value of the edge between points p1 and p4

        if (p1p2 == 0 || p1p3 == 0 || p1p4 == 0) { // checks whether any edge has 0 length value or not
            return false;
        }

        if (p1p2 > p1p3 && p1p2 > p1p4) {  // Here p1p2 is greater so point opposite to p1 is p2
            if (p1p3 == p1p4) {
                return checkOpposite(p2, p3, p4);
            }
        } else if (p1p3 > p1p2 && p1p3 > p1p4) {  // Here p1p3 is greater so point opposite to p1 is p3
            if (p1p2 == p1p4) {
                return checkOpposite(p3, p2, p4);
            }
        } else if (p1p4 > p1p2 && p1p4 > p1p3) {  // Here p1p4 is greater so point opposite to p1 is p4
            if (p1p2 == p1p3) {
                return checkOpposite(p4, p2, p3);
            }
        }
        return false;
    }

    public static void main(String[] args) {
        // write your code here
        Scanner scan = new Scanner(System.in);
        int[] p1 = new int[]{scan.nextInt(), scan.nextInt()};
        int[] p2 = new int[]{scan.nextInt(), scan.nextInt()};
        int[] p3 = new int[]{scan.nextInt(), scan.nextInt()};
        int[] p4 = new int[]{scan.nextInt(), scan.nextInt()};

        boolean isASquare = validSquare(p1, p2, p3, p4);

        System.out.printf("\n%b", isASquare);
    }
}

/*
  Test Case 1:

  Input: 0 0
         1 1
         1 0
         0 1
  Output: true

  Test Case 2:

  Input: 0 0
         1 1
         1 0
         0 12
  Output: false

  Test Case 3:

  Input: 1 0
        -1 0
         0 1
         0 -1
  Output: true
 */
