Leadership Principles: Customer Obsession · Invent and Simplify · Earn Trust · Deliver Results

Situation
After launching our cancellation/rescheduling fee policy, we noticed a spike in help‐center tickets from users charged fees for reasons beyond their control (e.g., partner refusal to serve). This manual dispute process drove help‐center CSAT down by 5%.

Task
I owned improving customer satisfaction by giving users a self-serve way to contest and, when valid, automatically refund inappropriate fees—without overloading support teams.

Action
Dug into help-center logs and CSAT feedback to quantify fee-dispute patterns and root causes.

Convened brainstorming sessions with product, support, and engineering to define a streamlined resolution flow.

Designed and built a chatbot integrated with our policy microservice to:

Prompt users for the reason behind their cancellation.

Apply business rules (first‐time waivers, valid exceptions).

Automatically trigger refunds when criteria were met.

Piloted the chatbot on a subset of disputes, gathered user feedback, and iterated on conversational flows and edge‐case handling.

Rolled out the bot to all customer channels and monitored CSAT trends closely post-launch.

Result
Increased help‐center CSAT by 8% after launch.

Reduced manual fee-dispute handling time, allowing support staff to focus on higher-value issues.

Earned praise from leadership for delivering a frictionless customer experience and restoring trust.




Clarified Metrics & Scale
Monthly cancellations: 100 K total (60 K customer-initiated) across India and UAE

Daily disputes: ~200 tickets; previously 40% (~80) refunded manually

Post-launch automation: 3 cohorts (gaming, genuine, unsure) classified by LLM with 80% accuracy

Auto-refunds resolved ~60% of disputes (~120 cases/day), leaving ~80 for human review

CSAT improvement (A/B tested): from 73% baseline to 79% post-bot rollout


Error-Rate Breakdown

80% classification accuracy lacks false-positive/false-negative splits; potential unwarranted refunds or rejected valid cases.

Cost vs. Benefit

No analysis of incremental refund costs vs. savings in support headcount or CSR time.

Edge-Case Coverage

Unclear which “unsure” requests required human fallback and how frequently they occurred. (We have benchmarked the )

Long-Term Root Causes

Policy automation doesn’t address upstream partner refusals; refunds may mask systemic service gaps.


Last year at my company, we rolled out a new cancellation and rescheduling fee policy to reduce last-minute changes. However, within the first week, we saw an unexpected surge in help-center tickets, particularly from our UAE and India markets. Users were being charged fees for circumstances beyond their control, causing our CSAT scores to drop from 78% to 74%. Our support team was struggling - ticket resolution times doubled from 15 to 30 minutes, and we were receiving about 120 complaints daily about unfair fees. It quickly became clear that our policy needed immediate attention.

As the owner of the policy system, I was tasked by our product director to develop a self-serve solution that would improve customer satisfaction while reducing the burden on our support team. My primary responsibilities included redesigning the fee assessment logic to handle edge cases more fairly, implementing automated resolution paths, and finding ways to bring our CSAT scores back to acceptable levels. I needed to balance maintaining the policy's original intent of reducing last-minute changes while ensuring we weren't unfairly penalizing customers for circumstances outside their control.

I began by collaborating with our help center team and policy system stakeholders to understand the most pressing issues. After analyzing the patterns in customer complaints, I developed a two-phase solution approach. For immediate relief, I implemented a rules-based chatbot that automatically processed refunds for customers' first few incidents, which quickly reduced the load on our support team.

For the long-term solution, I proposed and developed an LLM-based system that could intelligently assess customer situations. I ran the LLM in shadow mode alongside our customer service agents for two weeks, comparing its decisions with human agents to validate its effectiveness. Through multiple iterations of prompt engineering, I refined the model's ability to accurately categorize legitimate cancellation reasons and determine appropriate fee adjustments.

I then orchestrated a gradual rollout through A/B testing, starting with 10% of our user base and slowly expanding based on performance metrics. Throughout the implementation, I maintained a fallback option allowing customers to connect with human agents if needed, ensuring we didn't leave anyone without support during the transition.

The results exceeded our expectations. Within two months of full deployment, our CSAT scores not only recovered but improved to 77%, surpassing our pre-issue levels. The automated system significantly reduced the burden on our support team, bringing average ticket resolution time down to 17 minutes. This efficiency improvement, combined with the reduced need for human intervention, led to meaningful cost savings for our support operations. What I found particularly rewarding was seeing how other teams across the company began adopting our LLM-based approach as a template for their own support automation initiatives. The solution proved scalable across all our global markets while maintaining consistent customer experience levels. Looking back, this experience taught me valuable lessons about the importance of rapid iteration and testing when implementing new technologies, as well as the need to balance automation with human oversight. Most importantly, it showed me how adapting quickly to unexpected challenges while keeping customer needs at the forefront can lead to solutions that surpass the original system's effectiveness


--------- Final Structure

Situation:
We have rolled out new policy system to enforce cancellation and reschedule policy. 
We observed a lagging indicator in ticket type counts. 
We were notified by the CXPX team that there has a significant tickets for unfair fee applied on a request. 
This was not the case in UAE and singapore. Our mean tickets per day has increased from 30 to 150. 
This bombed out CSAT scores from 76% to 72% and also increase the First ticket resolution time to 30 mins from earlier 15 mins.
Our team wanted to contain this situation before further escalations. Main reason being that we have introduced tiered rates for 
cancellation (as customer cancels last minute we charge a higher fee). 

Task:
To improve CSAT scores 
To reduce FRT of this ticket type which decreases load on support executives thereby reducing costs

Action:
We had planned a incremental rollout to utilise existing chatbot architecture to implement a self serve flow. The first phase includes a quick fix to support the dropping CSAT scores and decrease the load on support executives

We have incrementally rolledout a self serve flow which invalidates most of the users who are trying to take advantage of the system (using fraud scores that are pre calculated across UC) and providing a limit on the number of times a customer can request refund in a year with a fallback to human agent for resolution. This has supported the CSAT score from dropping and decreased the load on support agents. We saw further scope on this using LLM's.

Phase two is integrating LLM into chatbot to provide as another line of defence before human intervention:
By understanding the SOP of agents dealing with these tickets,  
we infered that agents asess the customers reason provided along with request state, partners location from customers address, 
partners trust score to determine if a refund can be provided. We have used this information along with Open AI's 3.5 model by
prompt engineering it to assess the customer refund request. To test the performance of this and improve the model. 
We incorporated a shadow based testing model where the model evaluates a customers ticket along with request information to 
make a decision on whether to give refund. Initial model performed poorly where it was giving refunds to customer which the agent 
deemed as not refund case. Further iteration of giving detailed prompts along with more clean data improved the performance where 
in shadow mode it has achieved an accuracy of over 85% compared to human resolution. To further bias the model towards not refunding 
as we don't want to refund major customer unless they have a genuine reason. We chose a high precision score of over 90% to determine 
whether to refund. 

What followed was an incremental rollout using AB testing based 
on ticketIds to control the chatbot. It was a major success and was the 
first implementation of LLM into chatbots in UC.

Result:
CSAT scores improved from 72% to 78% (2% improvement)
FRT has improved from 30mins to 5mins as majority of the tickets were closed during the hard rule or the 
LLM phase and did not require agent to resolve.
Paved way for future LLM integration into chatbot across UC.

Bias for action,
Ownership
On trust
Delivery results
Invent and simplify

SDE 2 
Delivery results
Learn and be curious


Questions:

1. Whats the most interesting project you have worked on and you did not get chance to talk yet.
2. Tell me about your greatest professional success that wasn't on your resume.
3. Tell me about a challenging decision you havent talked aboutn with challanges / results.
4. Describe a project or idea that wasn't shared.
5. Are there any qualificaitons that haven't comeup in an interview yet and had a impact using that.
6. Is there a prod moment or accomplishment that we haven't talked yet.



Failure model

Situation: When we expanded our policy system to include tiered cancellation / reschedules fees (charging more for last-minute changes), I was responsible for the technical rollout. Based on our successful launches in the UAE and Singapore, I pushed for a rapid deployment in the India market. I assumed that because the backend logic was sound and the "tiered" model had worked elsewhere, the customer reaction would be manageable.

The Failure: I overlooked the cultural and behavioral differences in the India market, where cancellation frequency and customer pushback are significantly higher. I ignored a suggestion from the CX team to include a "grace period" or a self-serve appeal flow at launch. I prioritized "Bias for Action" over "Customer Obsession," believing we could handle any fallout manually.

The Impact: The result was a disaster for our support operations. Daily tickets for "unfair fees" spiked from 30 to 150. Our CSAT score dropped from 76% to 72%, and the First Response Time (FRT) doubled to 30 minutes, effectively "bombing out" the support queue and causing massive burnout among our agents.

Task: My task changed from "managing a rollout" to "emergency damage control." I had to take full ownership of the ticket spike and design a technical solution to automate the mess I had created.

Action: I immediately met with the CX lead to apologize and understand the specific "SOP" agents used to resolve these disputes.

Short-term Fix: I personally designed a "Hard Rule" self-serve flow using fraud scores to filter out bad actors and provide instant refunds for low-risk, first-time offenders.

Long-term Solution: To handle complex cases, I led the integration of an LLM (GPT-3.5) into our chatbot. I implemented "Shadow Testing" where the model's decisions were compared against human agents.

The Pivot: When initial accuracy was low, I realized the data was "noisy". I personally cleaned the prompt data and increased the precision threshold to 90% to ensure we only automated clear-cut cases, protecting the firm’s revenue while satisfying the customer.

Result: The CSAT recovered to 78%, and we actually improved the FRT to 5 minutes—better than it was before the failure. However, the most important outcome was the mechanism I implemented: any future pricing or policy change now requires a "CX Impact Assessment" and a mandatory "Self-Serve Fallback" plan before it can be approved for rollout.