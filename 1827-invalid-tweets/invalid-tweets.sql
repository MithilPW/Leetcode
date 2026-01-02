# Write your MySQL query statement below
select tweet_id
FROM tweets
where length(content) > 15