
import chromadb

client = chromadb.Client()

collection = client.create_collection("documents")

collection.add(
    documents=["Python is a programming language."],
    ids=["doc1"]
)

results = collection.query(
    query_texts=["What is Python?"],
    n_results=1
)

print(results)