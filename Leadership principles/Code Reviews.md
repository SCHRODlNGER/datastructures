STAR Story: Instituting Code & Design Reviews
Leadership Principles: Ownership · Insist on the Highest Standards · Dive Deep · Deliver Results

Situation
When I joined the UWAT team at JP Morgan Chase, there was no formal code- or architecture-review process. Critical components of our Controls Requirement Rating (CRR) system lacked shared documentation, and a major architectural flaw surfaced two weeks after release—forcing a full rework.

Task
I owned the initiative to establish rigorous code reviews and technical design sessions for all new features, beginning with the next CRR release, to improve code quality and team alignment.

Action
Secured buy-in from peers and management to mandate pull-request reviews before merges and to schedule design walkthroughs for major changes.

Documented end-to-end system architecture and inter-service interactions in Confluence, ensuring everyone had a single source of truth.

Facilitated bi-weekly design-review meetings, encouraging engineers at all levels to critique implementations against SOLID principles.

Cultivated a blameless review culture so issues surfaced early and feedback was welcomed.

Took ownership in building git pipelines and creating commit hooks which check for linting, Unit test coverage and build success which reduced the linting issue we have faced and forced creating proper unit tests which check for response by enforcing lines covered, branches covered, conditions covered percentages. 


Result
Saved an estimated two developer-weeks per release by eliminating large-scale rework.

Reduced post-production defects in the CRR system by 40%.

Cut onboarding time for feature changes by 30%.

Improved employee satisfaction scores by 10%, with engineers noting that “the system is now easier to work on and extend.”


Scaling & Sustainability

Without clear SLAs or automation (lint gates, template checkers), review load could bottleneck as the team grows.

Metric Granularity

Percent-based improvements are strong, but raw numbers (total defects, total developer hours) would clarify scale.

Review Overhead

No discussion of how added process impacted feature velocity or how you prevented reviews from becoming “rubber-stamp” rituals.

Documentation Maintenance

Initial documentation is great, but processes for ongoing updates and owner accountability aren’t defined.

Cultural Buy-In Beyond UWAT

It’s unclear if other teams adopted your approach or if this initiative remains siloed.


After joining JP Morgan Chase's UWAT team from my startup background, I quickly noticed some concerning gaps in our development practices. The team lacked any formal code review or architecture review process, which was particularly worrying given the critical nature of our Controls Requirement Rating system. The situation came to a head when we discovered a major architectural flaw in the CRR system just two weeks after release. This flaw wasn't caught earlier because key components had no documentation, and we'd need to completely rework the system.

As a experienced developer on the team, I took the initiative to address these systemic issues. My primary task was to establish a robust code review process and quality standards that would prevent similar problems in the future. This meant I needed to convince several skeptical team members who argued that adding reviews would slow down our delivery. I was also responsible for developing documentation requirements and implementing a more structured development workflow that would maintain our velocity while improving code quality. The challenge was finding a balanced approach that would win over the team.

I began by conducting a thorough analysis of our codebase, documenting specific issues like excessive logging of sensitive data and structural problems that could impact maintainability. Armed with concrete examples, I scheduled a one-on-one meeting with my manager to present my findings and propose solutions. I emphasized how these issues could affect our system's security and scalability, backing my concerns with specific instances from our recent architectural flaw incident.

After getting my manager's support, I proposed a gradual approach to implementing changes, starting with online code reviews. Rather than forcing an immediate overhaul that might face resistance, I introduced regular team-wide code review sessions via Zoom. During these sessions, I had developers walk through their implementations, fostering a collaborative learning environment. This approach allowed team members to see the value of code reviews firsthand while building their confidence in the process. I made sure to keep these sessions focused and efficient to address concerns about impact on delivery speed.


Took ownership in building git pipelines and creating commit hooks which check for linting, Unit test coverage and build success which reduced the linting issue we have faced and forced creating proper unit tests which check for response by enforcing lines covered, branches covered, conditions covered percentages. 

The results exceeded my expectations. Our team's velocity increased from 280 to 325 hours per sprint, primarily because we caught issues earlier and reduced the back-and-forth between QA and development. The collaborative code review sessions created natural learning opportunities - I often saw junior developers implementing patterns they'd learned from senior team members' feedback. More importantly, we caught several critical missing features during reviews that would have otherwise made it to production, preventing potential incidents like our earlier architectural flaw. The team's initial skepticism transformed into active engagement, with developers regularly volunteering to lead review sessions. This shift in culture led to increased knowledge sharing across the team, breaking down previous silos. Given this success, the team is now moving towards implementing offline code reviews, a practice they had initially resisted. Looking back, I learned that introducing significant process changes requires both concrete evidence of the problem and a gradual, collaborative implementation approach that demonstrates immediate value to the team.


----------- Final

Situation
After joining JP Morgan Chase's UWAT team from a startup background, I immediately noticed critical gaps in our software quality practices. There was no formal code or architecture review process, and unit tests were designed to simply maximize line coverage rather than validate outcomes. This lax approach to quality resulted in the release of a major architectural flaw in our Controls Requirement Rating (CRR) system just two weeks after launch. 
The issue was compounded by a lack of documentation, making the root cause difficult to trace and understand.

Task
Given the critical nature of our system and the visibility of the recent incident, I made it my responsibility to overhaul our development process. My main goals were:
Implementing a robust code review process that prioritized in-depth peer reviews over superficial approvals.
Establishing meaningful unit testing standards focused on verifying expected results, not just coverage.
Creating documentation guidelines to support maintainability and team onboarding.
Overcoming cultural resistance from teammates concerned these changes would slow delivery.

Action
Diagnosed the Problem: Conducted a detailed analysis of the codebase, highlighting instances of "rubber-stamped" code reviews and unit tests that simply exercised code paths without asserting real outcomes. Documented how these deficiencies contributed to our CRR system flaw.
Secured Buy-In: Presented findings in a one-on-one with my manager, emphasizing the business risk and backing arguments with concrete examples.
Gradual Rollout: Proposed starting with online code review sessions to foster a collaborative learning environment. Demonstrated value by walking through recent bugs and fixes in these sessions.
Built Automation: Developed git commit hooks and CI pipelines to enforce code linting and minimum unit test coverage thresholds. The new process required that all code changes undergo review and that unit tests actually check for correct results, not just lines executed.
Led by Example: Encouraged junior developers by involving them in reviews and pairing them with senior teammates. Maintained a focus on constructive feedback and shared learning during team reviews.

Result
The team's delivery velocity increased from 280 to 325 hours per sprint, reflecting faster, less error-prone development cycles.
Caught multiple critical issues in reviews before production, preventing further flawed launches.
Team skepticism turned to active engagement as members volunteered to lead review sessions and adopted better engineering habits.
Quality culture shifted: code reviews became substantive, unit tests meaningful, and knowledge sharing improved. Documentation standards were upheld.
The team is now piloting offline code review practices, a significant leap from initial resistance.
Through this experience, I learned the value of using evidence to gain consensus and the importance of starting small to drive lasting process improvements.



Since you’ve asked for a comprehensive study version, I’ve expanded your experience into a long-form STAR narrative. This version emphasizes Ownership and Insisting on the Highest Standards while maintaining the specific technical and organizational details we discussed.

Study this version to understand how to "connect the dots" between a technical problem and a business result.

Leadership Principle Focus: Ownership & Insist on Highest Standards
Situation: The Architectural Dead-End
Upon joining the UWAT team at JP Morgan Chase as a software engineer, I was tasked with contributing to the Controls Requirement Rating (CRR) system. I quickly identified a systemic lack of formal engineering rigor: there were no mandatory code reviews, no architecture walkthroughs, and unit testing was treated as a "check-the-box" exercise for line coverage rather than logic validation.

This lack of oversight culminated in a critical architectural flaw. While analyzing a new requirement for a "Risk Approver" workflow, I realized the existing data model was designed to overwrite risk records directly. It lacked any state immutability or versioning history. This meant that if an approver rejected a change, the system had no mechanism to revert to the previous state. The team had already invested five developers’ worth of effort over a full sprint into this model, which was now essentially a "dead end" for our future roadmap.

Here is your story restructured into the **SPSIL** (Situation, Problem, Solution, Implementation, Learning/Results) format, strictly adhering to the facts you provided.

---

### **S — Situation**

I joined the UWAT team at JPMorgan Chase, coming from a startup background, to work on the Controls Requirement Rating (CRR) system. At the time, the team had no formal process for code or architecture reviews, and the existing unit tests were designed to maximize line coverage rather than validate functional outcomes.

### **P — Problem**

Two weeks after a release, a major architectural flaw was discovered: the risk system's data model was designed to overwrite records with no mechanism to maintain history or revert changes. This directly blocked a critical stakeholder requirement for a risk approval workflow. This failure resulted in **one full sprint of wasted work for five developers**. I identified that the root causes were a lack of documentation, "rubber-stamped" reviews, and significant "FARM findings" (internal code quality issues) that required frequent production hotfixes.

### **S — Solution**

I proposed a two-pronged solution:

1. **Technical Redesign:** Implementing a separate database/state to store "pre-approval" risks, allowing for reverts if an approval failed.
2. **Process Overhaul:** Introducing mandatory architecture and code reviews, alongside automated quality gates to enforce high engineering standards before code reached production.

### **I — Implementation**

* **Securing Buy-In:** I presented a detailed analysis of the wasted sprint and existing hotfixes to my manager. To counter the "we don't have time" argument from the team, I explained that fixing the model now was easier than writing complex one-time data consistency scripts after a full production release.
* **Collaborative Reviews:** I initiated team-wide Zoom review sessions to walk through implementations, fostering a learning environment that turned initial skepticism into active engagement.
* **Automation:** I developed local git pre-commit and pre-push hooks to fix linting and check coverage.
* **CI/CD Gates:** I built a GitHub pipeline (independent of the organization-wide Jules pipeline) that enforced an **80% branch coverage threshold** and passed linting checks before allowing any merge to the develop branch.

### **L — Learning & Results**

* **Increased Velocity:** Sprint velocity increased from **280 to 325 points**, as the team spent significantly less time on rework and emergency hotfixes.
* **Quality Metrics:** We achieved a **90% reduction in FARM findings** and maintained a consistent 80% branch coverage standard.
* **Culture Shift:** The team transitioned from resisting reviews to volunteering to lead them. Junior developers began implementing senior-level patterns discovered during reviews.
* **Business Outcome:** The system successfully supported the new approval workflow without further architectural changes, and the team is now moving toward offline code reviews.
