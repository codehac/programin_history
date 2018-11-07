import java.util.*;
import java.io.*;
import java.lang.*;
class seinfeld{
public static void main(String []args) throws Exception{
 Scanner cin=new Scanner(System.in);
 String s="";
 int j=1;
 while(true){
	 s=cin.next();
	 if(s.charAt(0)=='-')
		 break;
     Stack<Character> st=new Stack<Character>();
	    int count=0;
	 for(int i=0;i<s.length();i++){
	      if(s.charAt(i)=='}' && st.size()==0){
	      	count++;
	      	st.push('{');
	      }
	      else if(s.charAt(i)=='{')
	      st.push('{');
	      else
	      st.pop();
		}	 
	 
	 count+=st.size()/2;
	 System.out.println(j+". "+count);
	 j++;
 }
}
}