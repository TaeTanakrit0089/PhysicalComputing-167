@echo off
curl "https://portal.it.kmitl.ac.th:4081/internal/dologin.php?NTLM=0&hash=individual_overall_5434" ^
  -H "Content-Type: application/x-www-form-urlencoded" ^
  --data-raw "kerio_username=iot&kerio_password=iot"
