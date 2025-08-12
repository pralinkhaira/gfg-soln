class Solution:
    def minMaxCandy(self, prices, k):
        # code here
        n = len(prices)
        prices.sort()
        
        #Min Price
        min_price = 0
        i, j = 0, n-1
        while i <= j:
            min_price += prices[i]
            i += 1
            j -= k
        
        #Max Price
        max_price = 0
        i, j = 0, n-1
        while i <= j:
            max_price += prices[j]
            j -= 1
            i += k
        return [min_price, max_price]