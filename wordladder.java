import java.util.ArrayList;
import java.util.HashSet;
import java.util.List;

public class wordladder{
    static List<List<String>> res;
    static HashSet<String> set;
    static int min = Integer.MAX_VALUE;
    public static void main(String[] args) {
        String beginWord = "qa";
        String endWord = "sq";
        String[] arr = {"si","go","se","cm","so","ph","mt","db","mb","sb","kr","ln","tm",
                        "le","av","sm","ar","ci","ca","br","ti","ba","to","ra","fa","yo",
                        "ow","sn","ya","cr","po","fe","ho","ma","re","or","rn","au","ur",
                        "rh","sr","tc","lt","lo","as","fr","nb","yb","if","pb","ge","th",
                        "pm","rb","sh","co","ga","li","ha","hz","no","bi","di","hi","qa",
                        "pi","os","uh","wm","an","me","mo","na","la","st","er","sc","ne",
                        "mn","mi","am","ex","pt","io","be","fm","ta","tb","ni","mr","pa",
                        "he","lr","sq","ye"};
        List<String> test = new ArrayList<>();
        for(String str : arr) test.add(str);
        findLadders(beginWord, endWord, test);
        for(List<String> ss : res){
            System.out.println(ss.toString());
        }
    }


    public static List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        set = new HashSet<String>(wordList);
        res = new ArrayList<List<String>>();
        List<String> temp = new ArrayList<String>();
        temp.add(beginWord);
        HashSet<String> seen = new HashSet<String>();
        seen.add(beginWord);
        solve(endWord, temp, seen);
        return res;
    }


    public static void solve(String ew, List<String> temp, HashSet<String> seen) {
        int n = temp.size();
        System.out.println(temp.toString());
        if (temp.get(n - 1).equals(ew)) {
            if (n > min)
                return;
            else if (n < min) {
                min = n;
                res.clear();
                res.add(new ArrayList<String>(temp));
                return;
            }
            res.add(new ArrayList<String>(temp));
            return;
        }

        char[] cw = temp.get(n - 1).toCharArray();
        for (int i = 0; i < cw.length; i++) {
            for (int j = 0; j < 26; j++) {
                cw[i] = (char) (j + 'a');
                String tt = new String(cw);
                if (set.contains(tt)) {
                    if (!seen.contains(tt)) {
                        seen.add(tt);
                        temp.add(tt);
                        solve(ew, temp, seen);
                        seen.remove(tt);
                        temp.remove(n);
                    }

                }
            }
            cw = temp.get(n - 1).toCharArray();
        }
        return;
    }
}