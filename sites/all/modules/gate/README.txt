+-----------------------------+
|  GATE MODULE DOCUMENTATION  | 
+-----------------------------+
|          8/22/2013          |
+-----------------------------+

The Gate module has a simple usage for development. To test it, open the .module folder, 
and navigate to line 92. The variable "$fake_shib" is the variable that contains the ca-
-mpus ID. Change this variable value to something you know that is not a campus ID. I use
'spongebob'. Save it, and goto localhost/x/gate, x being your instance directory. You should
be forwarded to localhost/x/nope. Now change the variable to a real campus ID, navigate to gate,
and refresh. You should be taken to localhost/x/yup.


Functionality left to implement: 

Still need to implement a simple if statement that determines wether or not the campus id is a student or faculty,
AFTER determining if it exist in our system. IF campus ID exists, but is not a student, then they are a faculty. Go ahead
and play around.

