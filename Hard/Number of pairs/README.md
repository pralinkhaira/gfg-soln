<h2><a href="https://www.geeksforgeeks.org/problems/number-of-pairs-1645358985/1?page=9&difficulty=Hard&sortBy=submissions">Number of pairs</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size: 18px;">The director of your college&nbsp;is&nbsp;planning to send 2 people to the ICPC&nbsp;regionals. He&nbsp;wants them to be from different branches. You will be given a list of pairs of student ids. Each pair is made of students from the same branch. Determine how many pairs of students from different branches they can choose from.</span></p>
<pre><span style="font-size: 18px;"><strong>Example 1:
Input:</strong>
N=5
P=3
pairs[]={{0,1},
         {2,3},
         {0,4}}
<strong>Output:</strong>
6
<strong>Explanation:</strong>
Their are total five studets 0,1,2,3,4.
Students [0,1,4] are from same bracnh while 
[2,3] are from a different one.So we can choose
different pairs like: [0,2],[0,3],[1,2],[1,3],
[4,2],[4,3]</span></pre>
<p>&nbsp;</p>
<pre><span style="font-size: 18px;"><strong>Example 2:
Input:</strong>
N=4 
P=1
pairs[]={{0,2}}
<strong>Output:</strong>
5
<strong>Explanation:</strong>
[0,1],[0,3],[2,1],[2,3] and [1,3] are all possible 
pairs because [0,2],[1] and [3] all belongs to 
different branches.</span></pre>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Your Task:&nbsp;&nbsp;</strong><br>You don't need to read input or print anything. Your task is to complete the function <strong>numberOfPairs()</strong>&nbsp;which takes the 2d array pairs[], its size P<strong>&nbsp;</strong>and an integer N representing total number of students<strong>&nbsp;</strong>as input parameters&nbsp;and returns the total number of pairs(as explianed in the question).</span>.</p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Expected Time Complexity:</strong> O(N)<br><strong>Expected Auxiliary Space:</strong> O(N)</span></p>
<p>&nbsp;</p>
<p><span style="font-size: 18px;"><strong>Constraint:</strong><br>1&lt;=N&lt;=10<sup>5</sup><br>1&lt;=P&lt;=10<sup>4</sup><br>0&lt;=P[i][0],P[i][1]</span></p>
<p>&nbsp;</p></div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Dynamic Programming</code>&nbsp;<code>Graph</code>&nbsp;<code>Disjoint Set</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;