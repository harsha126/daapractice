import java.util.ArrayList;
import java.util.HashMap;
import java.util.HashSet;
import java.util.LinkedList;
import java.util.List;
import java.util.Map;
import java.util.Queue;

public class wordladder2 {
    static HashMap<String, List<String>> adj;
    static List<List<String>> res;
    int min = Integer.MAX_VALUE;
    public static void main(String[] args) {
        String beginWord = "aaaaa";
        String endWord = "ggggg";
        String[] arr = {"aaaaa","caaaa","cbaaa","daaaa","dbaaa","eaaaa","ebaaa",
        "faaaa","fbaaa","gaaaa","gbaaa","haaaa","hbaaa","iaaaa","ibaaa","jaaaa",
        "jbaaa","kaaaa","kbaaa","laaaa","lbaaa","maaaa","mbaaa","naaaa","nbaaa",
        "oaaaa","obaaa","paaaa","pbaaa","bbaaa","bbcaa","bbcba","bbdaa","bbdba",
        "bbeaa","bbeba","bbfaa","bbfba","bbgaa","bbgba","bbhaa","bbhba","bbiaa",
        "bbiba","bbjaa","bbjba","bbkaa","bbkba","bblaa","bblba","bbmaa","bbmba",
        "bbnaa","bbnba","bboaa","bboba","bbpaa","bbpba","bbbba","abbba","acbba",
        "dbbba","dcbba","ebbba","ecbba","fbbba","fcbba","gbbba","gcbba","hbbba",
        "hcbba","ibbba","icbba","jbbba","jcbba","kbbba","kcbba","lbbba","lcbba",
        "mbbba","mcbba","nbbba","ncbba","obbba","ocbba","pbbba","pcbba","ccbba",
        "ccaba","ccaca","ccdba","ccdca","cceba","cceca","ccfba","ccfca","ccgba",
        "ccgca","cchba","cchca","cciba","ccica","ccjba","ccjca","cckba","cckca",
        "cclba","cclca","ccmba","ccmca","ccnba","ccnca","ccoba","ccoca","ccpba",
        "ccpca","cccca","accca","adcca","bccca","bdcca","eccca","edcca","fccca",
        "fdcca","gccca","gdcca","hccca","hdcca","iccca","idcca","jccca","jdcca",
        "kccca","kdcca","lccca","ldcca","mccca","mdcca","nccca","ndcca","occca",
        "odcca","pccca","pdcca","ddcca","ddaca","ddada","ddbca","ddbda","ddeca",
        "ddeda","ddfca","ddfda","ddgca","ddgda","ddhca","ddhda","ddica","ddida",
        "ddjca","ddjda","ddkca","ddkda","ddlca","ddlda","ddmca","ddmda","ddnca",
        "ddnda","ddoca","ddoda","ddpca","ddpda","dddda","addda","aedda","bddda",
        "bedda","cddda","cedda","fddda","fedda","gddda","gedda","hddda","hedda",
        "iddda","iedda","jddda","jedda","kddda","kedda","lddda","ledda","mddda",
        "medda","nddda","nedda","oddda","oedda","pddda","pedda","eedda","eeada",
        "eeaea","eebda","eebea","eecda","eecea","eefda","eefea","eegda","eegea",
        "eehda","eehea","eeida","eeiea","eejda","eejea","eekda","eekea","eelda",
        "eelea","eemda","eemea","eenda","eenea","eeoda","eeoea","eepda","eepea",
        "eeeea","ggggg","agggg","ahggg","bgggg","bhggg","cgggg","chggg","dgggg",
        "dhggg","egggg","ehggg","fgggg","fhggg","igggg","ihggg","jgggg","jhggg",
        "kgggg","khggg","lgggg","lhggg","mgggg","mhggg","ngggg","nhggg","ogggg",
        "ohggg","pgggg","phggg","hhggg","hhagg","hhahg","hhbgg","hhbhg","hhcgg",
        "hhchg","hhdgg","hhdhg","hhegg","hhehg","hhfgg","hhfhg","hhigg","hhihg",
        "hhjgg","hhjhg","hhkgg","hhkhg","hhlgg","hhlhg","hhmgg","hhmhg","hhngg",
        "hhnhg","hhogg","hhohg","hhpgg","hhphg","hhhhg","ahhhg","aihhg","bhhhg",
        "bihhg","chhhg","cihhg","dhhhg","dihhg","ehhhg","eihhg","fhhhg","fihhg",
        "ghhhg","gihhg","jhhhg","jihhg","khhhg","kihhg","lhhhg","lihhg","mhhhg",
        "mihhg","nhhhg","nihhg","ohhhg","oihhg","phhhg","pihhg","iihhg","iiahg",
        "iiaig","iibhg","iibig","iichg","iicig","iidhg","iidig","iiehg","iieig",
        "iifhg","iifig","iighg","iigig","iijhg","iijig","iikhg","iikig","iilhg",
        "iilig","iimhg","iimig","iinhg","iinig","iiohg","iioig","iiphg","iipig",
        "iiiig","aiiig","ajiig","biiig","bjiig","ciiig","cjiig","diiig","djiig",
        "eiiig","ejiig","fiiig","fjiig","giiig","gjiig","hiiig","hjiig","kiiig",
        "kjiig","liiig","ljiig","miiig","mjiig","niiig","njiig","oiiig","ojiig",
        "piiig","pjiig","jjiig","jjaig","jjajg","jjbig","jjbjg","jjcig","jjcjg",
        "jjdig","jjdjg","jjeig","jjejg","jjfig","jjfjg","jjgig","jjgjg","jjhig",
        "jjhjg","jjkig","jjkjg","jjlig","jjljg","jjmig","jjmjg","jjnig","jjnjg",
        "jjoig","jjojg","jjpig","jjpjg","jjjjg","ajjjg","akjjg","bjjjg","bkjjg",
        "cjjjg","ckjjg","djjjg","dkjjg","ejjjg","ekjjg","fjjjg","fkjjg","gjjjg",
        "gkjjg","hjjjg","hkjjg","ijjjg","ikjjg","ljjjg","lkjjg","mjjjg","mkjjg",
        "njjjg","nkjjg","ojjjg","okjjg","pjjjg","pkjjg","kkjjg","kkajg","kkakg",
        "kkbjg","kkbkg","kkcjg","kkckg","kkdjg","kkdkg","kkejg","kkekg","kkfjg",
        "kkfkg","kkgjg","kkgkg","kkhjg","kkhkg","kkijg","kkikg","kkljg","kklkg",
        "kkmjg","kkmkg","kknjg","kknkg","kkojg","kkokg","kkpjg","kkpkg","kkkkg",
        "ggggx","gggxx","ggxxx","gxxxx","xxxxx","xxxxy","xxxyy","xxyyy","xyyyy",
        "yyyyy","yyyyw","yyyww","yywww","ywwww","wwwww","wwvww","wvvww","vvvww",
        "vvvwz","avvwz","aavwz","aaawz","aaaaz"};
        List<String> in = new ArrayList<String>();
        for(String str : arr) in.add(str);
        findLadders(beginWord, endWord, in);
        for(List<String> ss : res) System.out.println(ss.toString());
    }


    public static  List<List<String>> findLadders(String beginWord, String endWord, List<String> wordList) {
        adj = new HashMap<>();
        int n = beginWord.length();
        res = new ArrayList<List<String>>();
        HashSet<String> set = new HashSet<String>(wordList);
        HashMap<String, Integer> count = new HashMap<>();
        Queue<String> q = new LinkedList<String>();
        q.add(beginWord);
        count.put(beginWord, 0);
        while (!q.isEmpty()) {
            String curr = q.poll();
            int level = count.get(curr);
            boolean found = false;
            List<String> temp = new ArrayList<String>();
            for (int i = 0; i < n; i++) {
                char[] cr = curr.toCharArray();
                for (char ch = 'a'; ch <= 'z'; ch++) {
                    cr[i] = ch;
                    String tt = new String(cr);
                    if (set.contains(tt) && !tt.equals(curr)) {
                        if (!count.containsKey(tt)) {
                            q.add(tt);
                            count.put(tt, level + 1);
                            temp.add(tt);
                        } else {
                            if (count.get(tt) == count.get(curr) + 1) {
                                temp.add(tt);
                            }
                        }
                    }
                }
            }
            adj.put(curr, temp);
        }
        System.out.println(count.toString());
        // for(Map.Entry<String,List<String>> entry:adj.entrySet()){
        // System.out.println(entry.getKey()+" : "+entry.getValue().toString());
        // }
        HashSet<String> seen = new HashSet<>();
        List<String> temp = new ArrayList<String>();
        seen.add(beginWord);
        solve(beginWord, endWord, temp, seen);
        return res;
    }

    public static  void solve(String bw, String ew, List<String> temp, HashSet<String> seen) {
        temp.add(bw);
        if (bw.equals(ew)) {
            res.add(new ArrayList<String>(temp));
            temp.remove(temp.size() - 1);
            return;
        }
        List<String> t = adj.getOrDefault(bw,null);
        if(t!=null && t.size()!=0) for (String str : adj.get(bw)) solve(str, ew, temp, seen);
        
        temp.remove(temp.size() - 1);

    }
}
