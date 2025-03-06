from flask import Flask, request, jsonify
from google.oauth2.credentials import Credentials
from googleapiclient.discovery import build
from googleapiclient.errors import HttpError

app = Flask(__name__)

# 配置 OAuth 2.0 認證檔案
CLIENT_SECRET_FILE = 'credentials.json'

# Gmail API 授權
def get_gmail_service():
    creds = Credentials.from_authorized_user_file('token.json', ['https://www.googleapis.com/auth/gmail.readonly'])
    return build('gmail', 'v1', credentials=creds)

# Google Sheets API 授權
def get_sheets_service():
    creds = Credentials.from_authorized_user_file('token.json', ['https://www.googleapis.com/auth/spreadsheets'])
    return build('sheets', 'v4', credentials=creds)

@app.route('/trigger', methods=['POST'])
def trigger_email_to_sheet():
    try:
        # 取得 Gmail API 資料
        gmail_service = get_gmail_service()
        response = gmail_service.users().messages().list(userId='me', q='is:unread').execute()
        messages = response.get('messages', [])
        
        if not messages:
            return jsonify({"status": "No new messages found"})
        
        # 取第一封郵件內容
        message_id = messages[0]['id']
        message = gmail_service.users().messages().get(userId='me', id=message_id).execute()
        snippet = message.get('snippet', '')

        # 將內容寫入 Google Sheets
        sheets_service = get_sheets_service()
        SPREADSHEET_ID = 'your_google_sheet_id'
        range_name = 'Sheet1!A1'
        body = {'values': [[snippet]]}

        sheets_service.spreadsheets().values().append(
            spreadsheetId=SPREADSHEET_ID,
            range=range_name,
            valueInputOption='RAW',
            body=body
        ).execute()

        return jsonify({"status": "Email content added to Google Sheets"})

    except HttpError as error:
        print(f"An error occurred: {error}")
        return jsonify({"error": str(error)}), 500

if __name__ == '__main__':
    app.run(debug=True)
