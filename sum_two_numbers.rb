def two_sum(nums, target)
    map = {}
    nums.each_with_index do |x,index|
        difference = target - x
        if map[difference]
            return [map[difference],index]
        else
            map[x] = index
        end
    end
end