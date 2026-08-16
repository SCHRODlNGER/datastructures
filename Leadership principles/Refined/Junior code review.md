Situation: At Urban Company, I was the owner of the Policy System microservice. I was mentoring a junior developer on a critical "Routines" fee-flow project. In our microfrontend (MFE) architecture, the backend constructs a View-JSON that the client renders. A strict architectural boundary exists: the UI builder must be synchronous and pure; it should never trigger asynchronous information fetching.

Problem: During code review, I found the developer had implemented async calls directly within the UI builder logic. This violated our "separation of concerns" and threatened system stability. My initial code review comments were technical and brief, which led to defensive pushback from the developer who argued for a siloed implementation for "Routines" vs "On-Demand" flows.

Some of the comments being that: 
This is not scalable as new policy UI are being introduced to the system. It would result in creation of new UI builders even if the 

The "Self-Critical" Pivot: I realized that part of this friction was my responsibility—I hadn't required a High-Level Design (HLD) document before coding started. Without that shared blueprint, the junior was essentially "coding in the dark." To resolve the tension, I moved the discussion from a digital PR to a face-to-face meeting.

Action: In our meeting, I explained the Strategy Pattern approach, showing how we could decouple information fetching from UI generation. To ensure the junior didn't feel "overruled" by my seniority alone, I brought in our Team Lead to provide a neutral architectural perspective. We agreed  that an HLD would be mandatory moving forward to avoid such friction.

Result: The developer refactored the code to a pure-functional UI builder. This architectural "cleanliness" paid off immediately: when we launched the "Bundles" feature a month later, we reused the UI builder and only had to write a new fetcher. This reduced development time by 40% and allowed us to deliver the project ahead of schedule. Most importantly, I earned the developer's trust by providing a path for growth rather than just a "Correction," leading to a permanent shift in our team's HLD process.



Situation:
- Became owner of the policy system microservice at UC in early 2024, responsible for ensuring code quality and system extensibility
- Timeline context: completed on-demand request policies by Feb 2024, then working on routines flow (due Mar 2024) and upcoming bundles (due Apr 2024)
- Was formally tasked by manager to mentor a junior developer with 1.5 years experience who joined the team in Jan 2024
- During code review for routines policy display component, identified that junior developer had overcomplicated the implementation and overlooked existing extensible design
- Junior developer had written information fetching logic within the UI generation component, breaking clear distinction between the 3 subsystems (policy fetching, information gathering, UI JSON generation)
- Code lacked proper design principles like strategy pattern for integrating new request types and had poor variable naming

Task:
- Ensure all code pushed to policy system met highest standards while keeping system open for extension to new request types
- Help junior developer understand both how to implement solutions correctly and why specific approaches were necessary
- Resolve the conflict that arose from back-and-forth pushback during code review process
- Maintain team harmony while upholding technical standards and preparing system for upcoming bundles integration

Action:
- Initially highlighted design issues in code review with specific suggestions for improvements and clear reasoning
- When junior developer pushed back defending separate maintenance for on-demand vs routines, explained that from systems perspective they are simply requests with different policies applied
- Suggested meeting to discuss approach face-to-face when code review became too back-and-forth
- During meeting, went through all review comments one by one with friendly, fact-driven tone
- Explained how to structure display system around policy type instead of request type using strategy pattern
- Provided concrete examples: zero fee policies vs fee policies, cancellation-only vs cancellation+reschedule policies
- When junior developer remained hesitant, arranged quick chat with team lead to get additional perspective
- Recommended books on design patterns and clean code to support learning
- Had follow-up conversation with manager about how to better handle similar situations
- Established biweekly learning sessions for whole team to share knowledge without criticism

Result:
- Junior developer rewrote code to incorporate suggested changes
- When bundles were deployed, junior developer approached to acknowledge that integration went smoothly without major architectural bottlenecks
- Received praise from manager and VP for handling situation while sticking to facts when expressing opinions
- Biweekly learning sessions became ongoing ritual in parent team, encouraging knowledge sharing on topics ranging from tech to personal finance
- Successfully maintained high code quality standards while preserving positive working relationship and team dynamics