-- 方法1：排序法
function groupAnagrams(strs)
    local map = {}
    
    for _, str in ipairs(strs) do
        -- 将字符串转换为字符表并排序
        local chars = {}
        for i = 1, #str do
            chars[i] = str:sub(i, i)
        end
        table.sort(chars)
        
        -- 排序后的字符串作为 key
        local key = table.concat(chars)
        
        if not map[key] then
            map[key] = {}
        end
        table.insert(map[key], str)
    end
    
    -- 构建结果
    local result = {}
    for _, group in pairs(map) do
        table.insert(result, group)
    end
    
    return result
end

-- 方法2：计数法（性能更好）
function groupAnagrams2(strs)
    local map = {}
    
    for _, str in ipairs(strs) do
        -- 统计每个字符出现次数
        local count = {}
        for i = 1, 26 do
            count[i] = 0
        end
        
        for i = 1, #str do
            local c = str:byte(i) - string.byte('a') + 1
            count[c] = count[c] + 1
        end
        
        -- 将计数数组转换为字符串作为 key
        local key = table.concat(count, "#")
        
        if not map[key] then
            map[key] = {}
        end
        table.insert(map[key], str)
    end
    
    -- 构建结果
    local result = {}
    for _, group in pairs(map) do
        table.insert(result, group)
    end
    
    return result
end

-- 测试代码
local function printResult(result)
    print("[")
    for i, group in ipairs(result) do
        local items = {}
        for _, str in ipairs(group) do
            table.insert(items, '"' .. str .. '"')
        end
        print("  [" .. table.concat(items, ", ") .. "]")
    end
    print("]")
end

-- 测试用例
local test1 = {"eat", "tea", "tan", "ate", "nat", "bat"}
print("输入: {\"eat\", \"tea\", \"tan\", \"ate\", \"nat\", \"bat\"}")
print("\n方法1 - 排序法:")
printResult(groupAnagrams(test1))

print("\n方法2 - 计数法:")
printResult(groupAnagrams2(test1))


