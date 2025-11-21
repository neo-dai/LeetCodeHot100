function twoSum(nums, target)
    local num_to_index = {}
    for i = 1, #nums do
        local num = nums[i]
        local complement = target - num
        if num_to_index[complement] ~= nil then
            return {num_to_index[complement], i}
        end
        num_to_index[num] = i
    end
    return {}
end

-- 测试代码
local nums = {2, 7, 11, 15}
local target = 9
local result = twoSum(nums, target)

print("输入数组:")
for i = 1, #nums do
    io.write(nums[i] .. " ")
end
print("\n目标值: " .. target)
print("结果索引: " .. result[1] .. ", " .. result[2])
print("验证: nums[" .. result[1] .. "] + nums[" .. result[2] .. "] = " .. nums[result[1]] .. " + " .. nums[result[2]] .. " = " .. (nums[result[1]] + nums[result[2]]))
