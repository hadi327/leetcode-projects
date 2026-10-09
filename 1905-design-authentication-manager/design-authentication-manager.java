class AuthenticationManager {
    int timeToLive;
    Set<String> alive;
    Map<String, Integer> lives;
    public AuthenticationManager(int timeToLive) {
        this.timeToLive = timeToLive;
        lives = new HashMap<>();
        alive = new HashSet<>();
    }
    
    public void generate(String tokenId, int currentTime) {
        lives.put(tokenId, currentTime + timeToLive);
        alive.add(tokenId);
    }
    
    public void renew(String tokenId, int currentTime) {
        if(!lives.containsKey(tokenId)) return;
        if(lives.get(tokenId) <= currentTime){
            alive.remove(tokenId);
            return;
        }
        lives.put(tokenId, currentTime + timeToLive);

    }
    
    public int countUnexpiredTokens(int currentTime) {
        Set<String> tmp = new HashSet<>();
        for(String token : alive){
            if(lives.get(token) > currentTime){
                tmp.add(token);
            }
        }
        alive = tmp;
        return alive.size();
    }
}

/**
 * Your AuthenticationManager object will be instantiated and called as such:
 * AuthenticationManager obj = new AuthenticationManager(timeToLive);
 * obj.generate(tokenId,currentTime);
 * obj.renew(tokenId,currentTime);
 * int param_3 = obj.countUnexpiredTokens(currentTime);
 */