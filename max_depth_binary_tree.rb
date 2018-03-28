# Definition for a binary tree node.
class TreeNode
    attr_accessor :val, :left, :right
    def initialize(val)
        @val = val
        @left, @right = nil, nil
    end
end

# @param {TreeNode} root
# @return {Integer}
def max_depth(root)

    return 0 if root == nil

    level = 1
    level_right = max_depth(root.right)
    level_left = max_depth(root.left)

    if level_right > level_left
        level += level_right
    else
        level += level_left
    end

    return level
end