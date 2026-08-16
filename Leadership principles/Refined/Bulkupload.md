This happened when I was working in JPMC. We have a flow where Users can update their tools via a bulkupload.

Bulk upload is an async process that takes a file uploaded by the user and updates all the UTs present in the file. We had recently onboarded the CCB lob which leads with customer banking information. This widened the scope of what is considered as an User tool.



We had an intermittent issue where some of the UTs were stuck in processing and the pipeline was stuck for the uploaded file. This resulted in escalation mails from Lob Leadership as the UTs were stuck.



Prior to my joining the SOP for this issue was to manually update the entry of the UT to failed and let the User retry again. I am a developer which believes that most of the stuff should solved right and system should be able to handle cases with minimal human interaction unless necessary.



The SOP did not sit right with me and I had taken time outside of work to figure out the issue.


I deep dove into the issue to find UserTools that had were stuck in processing.

I found around 100 Usertools that were stuck in the processing since the BulkUpload feature was implemented. I took a sample of 20 UTs and analysed if there are any common features enabled for the UTs which caused the issue. I found no common features and all the data for these UTs was correct and this issue was not repeated when I had downloaded the UT information from PRod to Dev environment. With this I had concluded that individual UTs were being correctly processed. I then moved to check if there is an issue with the file that the users were uploading. These also seemed correct and the file was being processed correctly in Dev environment. The only common issue I have noticed is that the issue was predominantly occurring when multiple huge files are being processed. To test the hypothesis, I had pulled all the UTs to dev environment and the files that were processed in that batch.



This caused the same issue on dev and Uts which were stuck in processing were different. I then moved to understand the upload flow and how a file is being processed.

We had divided the processing on a file into 3 parts

1. Parse the file and extract UT information from the file

2. Process the extracted information and update the DB for the UTs

3. Generate report for the upload and complete processing.



I observed that processing was taking more than 10 mins when multiple huge files are being picked for processing. The processing is initialised by a CRON job that is run every 10 mins. With this I was able to conclude that the system was getting stuck in processing and the files were being stuck in processing.

