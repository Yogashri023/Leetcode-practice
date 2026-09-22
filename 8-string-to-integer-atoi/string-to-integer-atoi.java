class Solution {
    public int myAtoi(String s) {
        int i=0;
        int sign=1;
        int len=s.length();
        while(i<len && s.charAt(i)==' '){
            i++;
        }
        if (i<len && (s.charAt(i)=='+' || s.charAt(i)=='-')){
            sign=s.charAt(i)=='-'?-1:1;
            i++;
        }
        long num=0;
        int digit=0;
        while (i<len && Character.isDigit(s.charAt(i))){
            digit=s.charAt(i)-'0';
            num=num*10+digit;
             if (num> (Integer.MAX_VALUE)-digit/10){
            return sign==1?Integer.MAX_VALUE:Integer.MIN_VALUE;
        }
        
            i++;
        }
       
        return (int)num*sign;
    }
}