import java.io.*;
import  java.util.*;
class Robot 
{

  public static String moveRobot(int input1,int input2,String input3,String input4){
    String path[]=input3.split("-");
    int x=Integer.parseInt(path[0]);
    int y=Integer.parseInt(path[1]);
    String pos=path[2];
    String arr[]=input4.split(" ");
    int f=0;
    for(String s:arr)
    {
      if(s.equals("R"))
      {
        if(pos.equals("N"))
          pos="E";
        else if(pos.equals("E"))
          pos="S";
        else if(pos.equals("S"))
          pos="W";
        else if(pos.equals("NE"))
          pos="SE";
          else if(pos.equals("NW"))
          pos="NE";
          else if(pos.equals("SW"))
          pos="NW";
          else if(pos.equals("SE"))
          pos="SW";
        else
          pos="N";
      }
      else if(s.equals("L"))
      {
        if(pos.equals("N"))
          pos="W";
        else if(pos.equals("E"))
          pos="N";
        else if(pos.equals("S"))
          pos="E";
        else if(pos.equals("NE"))
          pos="NW";
          else if(pos.equals("NW"))
          pos="SW";
          else if(pos.equals("SW"))
          pos="SE";
          else if(pos.equals("SE"))
          pos="NE";
        else
          pos="S";
      }
      else if(s.equals("l"))
      {
        if(pos.equals("N"))
          pos="NW";
        else if(pos.equals("E"))
          pos="NE";
        else if(pos.equals("S"))
          pos="SE";
        else if(pos.equals("NE"))
          pos="N";
          else if(pos.equals("NW"))
          pos="W";
          else if(pos.equals("SW"))
          pos="S";
          else if(pos.equals("SE"))
          pos="E";
        else
          pos="SW";
      }
      else if(s.equals("r"))
      {
        if(pos.equals("N"))
          pos="NE";
        else if(pos.equals("E"))
          pos="SE";
        else if(pos.equals("S"))
          pos="SW";
        else if(pos.equals("NE"))
          pos="E";
          else if(pos.equals("NW"))
          pos="N";
          else if(pos.equals("SW"))
          pos="W";
          else if(pos.equals("SE"))
          pos="S";
        else
          pos="NW";
      }
      else if(f!=1)
      {
        if(s.equals("M")){ //add
            if(pos.equals("N"))
          {
            if(input2>y)
              y=y+1;
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("S"))
          {
            if(y>0)
              y=y-1;
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("E"))
          {
            if(input1>x)
              x=x+1;
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("NE"))
          {
            if((input1>x)||(input2>y)){
              x=x+1;
              y=y+1;
            }
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("SE"))
          {
            if((input1>x)||(y>0)){
              x=x+1;
              y=y-1;
            }
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("NW"))
          {
            if(input2>y||x>0){
              x=x-1;
              y=y+1;
            }
            else{
              f=1;
              break;
            }
          }
          else if(pos.equals("SW"))
          {
            if(x>0||y>0){
              x=x-1;
              y=y-1;
            }
            else{
              f=1;
              break;
            }
          }
          else
          {
            if(x>0)
              x=x-1;
            else{
              f=1;
              break;
            }
          }
        } 
      }
    }
    if(f!=1)
    return String.valueOf(x)+"-"+String.valueOf(y)+"-"+String.valueOf(pos);
    else
      return String.valueOf(x)+"-"+String.valueOf(y)+"-"+String.valueOf(pos)+"-"+"ER";
      
    }
    public static void main(String args[]){
      Scanner sc= new Scanner(System.in);
      int n=sc.nextInt(); sc.nextLine();
      int m=sc.nextInt(); sc.nextLine();
      String str=sc.nextLine();
      String str1=sc.nextLine();
    //  System.out.println(n+" "+m+" "+" "+str+" "+str1);
      System.out.println(moveRobot(n,m,str,str1));
    }
}