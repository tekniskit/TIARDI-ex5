Topic
-----
A multi-threaded server
 
References
----------
POSA2 Design Pattern book
 
Goal
----
Obtaining experience with POSA2’s Concurrency Patterns used together with POSA2’s Event Handling Patterns
 
Platform
--------
PC + windows
 
Assignment
----------
The PC server application from exercise 4 should be modified from a single-threaded to a multi-threaded server.
<ol>
<li>Select and use one of the following Concurrency patterns:
	<ul>
		<li>Half-Sync/Half-Async</li>
		<li>Leader/Followers</li>
	</ul>
	or alternatively using the Proactor architectural pattern.
</li>
<li>Integrate the selected pattern with the <strong>Acceptor/Connector</strong> and <strong>Reactor</strong> based server application from the previous exercises.</li>

<li>Implement and test the PC server application with minimum two PC client-applications requesting different services concurrently from the server.</li>
</ol>
An example scenario could be clients requesting patient information, sending log records and patient value records concurrently.

Product / delivery / deadline
-----------------------------
This is the second and final mandatory hand-in, where your solution to exercise 5 will encompass your solutions to exercise 4.
The hand-in must be structured as a word design document, with a short description of your client and server including UML class diagrams and UML sequence diagrams. The second part of the hand-in is a Visual Studio project with the source code.
 
Evaluation
----------
Your complete solution to Exercise 5 is to be finalized and handed-in as a Zip file via Campusnet- see the course schedule for deadline.