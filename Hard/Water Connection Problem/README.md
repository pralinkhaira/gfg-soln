<h2><a href="https://www.geeksforgeeks.org/problems/water-connection-problem5822/1?page=5&difficulty=Hard&sortBy=submissions">Water Connection Problem</a></h2><h3>Difficulty Level : Hard</h3><hr><div class="problems_problem_content__Xm_eO"><p><span style="font-size:18px">There are n houses and p water pipes in Geek Colony. Every house has at most one pipe going into it and at most one pipe going out of it. Geek needs to install pairs of tanks and taps in the colony according to the following guidelines. &nbsp;<br>
1. Every house with one outgoing pipe but no incoming pipe gets a tank on its roof.<br>
2. Every house with only one incoming and no outgoing pipe gets a tap.<br>
The Geek council has proposed a network of pipes where connections are denoted by three input values: ai, bi, di denoting the pipe of diameter di from house ai to house bi.<br>
Find a more efficient way for the construction of this network of pipes. Minimize the diameter of pipes wherever possible.<br>
<strong>Note</strong>: The generated output will have the following format. The first line will contain t, denoting the total number of pairs of tanks and taps installed. The next t lines contain three integers each: house number of tank, house number of tap, and the minimum diameter of pipe between them</span><span style="font-size:18px">.</span></p>

<p><br>
<span style="font-size:18px"><strong>Example 1:</strong></span></p>

<pre><span style="font-size:18px"><strong>Input:</strong>
n = 9, p = 6
a[] = {7,5,4,2,9,3}
b[] = {4,9,6,8,7,1}
d[] = {98,72,10,22,17,66} 
<strong>Output:</strong> 
3
2 8 22
3 1 66
5 6 10
<strong>Explanation:</strong>
Connected components are 
<strong><em>3-&gt;1, 5-&gt;9-&gt;7-&gt;4-&gt;6 and 2-&gt;8</em></strong>.
Therefore, our answer is<strong> 3</strong> 
followed by <strong>2 8 22, 3 1 66, 5 6 10.</strong></span></pre>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Your Task:</strong><br>
You don't need to read input or print anything. Your task is to complete the function&nbsp;<strong>solve()</strong>&nbsp;which takes an integer n(the number of houses), p(the number of pipes),the&nbsp;array a[] , b[] and&nbsp;d[] (where&nbsp;<strong>d[i]&nbsp;</strong>denoting the diameter of the ith pipe from the house <strong>a[i]</strong> to house <strong>b[i]</strong>) as input parameter and returns the array of&nbsp;pairs of tanks and taps installed i.e ith element of the array&nbsp;contains three integers: house number of tank, house number of tap and the minimum diameter of pipe between them. Note that, returned array <strong>must be sorted based on the house number&nbsp;containing a tank</strong> (i.e. smaller house number should come before a large house number).</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Expected Time Complexity:</strong>&nbsp;O(n+p)<br>
<strong>Expected Auxiliary Space:</strong>&nbsp;O(n+p)</span></p>

<p>&nbsp;</p>

<p><span style="font-size:18px"><strong>Constraints:</strong><br>
1&lt;=n&lt;=20<br>
1&lt;=p&lt;=50<br>
1&lt;=a[i],b[i]&lt;=20<br>
1&lt;=d[i]&lt;=100</span></p>
</div><br><p><span style=font-size:18px><strong>Topic Tags : </strong><br><code>Greedy</code>&nbsp;<code>DFS</code>&nbsp;<code>Graph</code>&nbsp;<code>Data Structures</code>&nbsp;<code>Algorithms</code>&nbsp;