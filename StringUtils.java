import java.util.List;
public class StringUtils {
	public static native String reverse(String s);
	public static native int firstNotOf(String s, String what);
	public static native int firstNotOf(String s, String what,int start);
	public static native int lastNotOf(String s,String what);
	public static native int lastNotOf(String s, String what, int start);
	/** 
		generatePermuations will return to you a maximum of 1000000 permutations
		the size of the returned list is dependent on the length of the input string
	**/
	public static native List<String> generatePermuations(String s);
	/** please limit the size this will eat up your memory**/
	public static native List<String> generatePermuations(String s,int limit);
	public static native int levenshteinDistance(String s1, String s2);
	public static native int optimalStringAlignmentDistance(String s1, String s2);
	public static native int damerauLevenshteinDistance(String s1, String s2);
	public static native int boyerMooreBadChar(String pattern, String text);
	static{
		System.loadLibrary("StringUtils");
	}
	
	public static void main(String[] args){
		String reversed = StringUtils.reverse("Hello from StringUtils");
		System.out.println(reversed);
		
	}
	
} 